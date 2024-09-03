#pragma once
#include <AutoOTA.h>
#include <GyverNTP.h>
#include <SettingsGyver.h>
#include <WiFiConnector.h>

#include "config.h"
#include "db.h"
#include "drawDisplay.h"

AutoOTA ota(F_VERSION, "AlexGyver/RipCalendar/main/project.json");
SettingsGyver sett("RipCalendar", &db);
bool test_f = false;

void build(sets::Builder& b) {
    {
        sets::Group g(b, "Время");
        b.Input(kk::time0, "Утро");
        b.Input(kk::time1, "День");
        b.Input(kk::time2, "Вечер");
        b.Input(kk::time3, "Ночь");
        b.Time(kk::print_time, "Время печати");
    }
    {
        sets::Group g(b, "Настройки");
        b.Input(kk::geo_lat, "Широта");
        b.Input(kk::geo_lon, "Долгота");
        b.Input(kk::gmt, "Часовой пояс");
        b.Input(kk::ntp_host, "NTP сервер");
        b.LED("Синхронизирован", NTP.synced());

        if (NTP.synced()) {
            b.Label("Время", NTP.timeToString());
        }

        if (b.Button("test_print"_h, "Тест")) {
            test_f = true;  // печать из лупа
        }
    }
    {
        sets::Group g(b, "Принтер");
        b.Switch(kk::ttl_mode, "TTL принтер");
        b.Switch(kk::turn180, "Повернуть на 180");
    }
    {
        sets::Group g(b, "WiFi");
        b.Input(kk::wifi_ssid, "SSID");
        b.Pass(kk::wifi_pass, "Pass", "");

        if (b.Button("wifi_save"_h, "Подключить")) {
            db.update();
            WiFiConnector.connect(db[kk::wifi_ssid], db[kk::wifi_pass]);
        }
    }

    if (b.Confirm("update"_h)) ota.update();

    if (b.build().isAction()) {
        switch (b.build().id()) {
            case kk::gmt:
                NTP.setGMT(b.build().value());
                break;
        }
    }
}

void update(sets::Updater& u) {
    if (ota.hasUpdate()) u.update("update"_h, "Доступно обновление. Обновить прошивку?");
}

void sett_tick() {
    sett.tick();
    ota.tick();

    if (test_f) {
        test_f = 0;
        requestAndPrint();
    }

    if (NTP.newSecond()) {
        if (db[kk::print_time] == NTP.daySeconds()) {
            requestAndPrint();
        }
    }
}