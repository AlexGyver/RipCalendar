#include <Arduino.h>
#include <CharMatrix.h>
#include <GyverNTP.h>
#include <WiFiConnector.h>

#include "drawDisplay.h"
#include "printer.h"
#include "settings.h"

void setup() {
    WiFiConnector.onConnect([]() {
        Serial.print("Local IP: ");
        Serial.println(WiFi.localIP());

        printer.print("Local IP: ");
        printer.println(WiFi.localIP());
        printer.feed(2);

        ota.checkUpdate();
    });
    WiFiConnector.onError([]() {
        Serial.println("WiFi error");

        printer.print("Start AP: ");
        printer.println(WiFi.softAPSSID());
        printer.println(WiFi.softAPIP());
        printer.feed(2);
    });

    Serial.begin(115200);
    Serial.println();

    printer_init();
    printer.print("RipCalendar v");
    printer.println(F_VERSION);

    // тест рандомными данными
    // CharMatrix<CHAR_X8> mx(384, 450);
    // Weather w;
    // w.code_max[0] = 45;
    // w.code_max[1] = 81;
    // w.code_max[2] = 95;
    // drawWeather(mx, w.temp_min, w.temp_max, w.wind_mid, w.code_max);
    // Serial.println(mx);
    // printer.printBuffer(mx);
    // Serial.println("Done");
    // return;

    db_init();

    WiFiConnector.connect(db[kk::wifi_ssid], db[kk::wifi_pass]);

    sett.begin();
    sett.onBuild(build);
    sett.onUpdate(update);

    NTP.setHost(db[kk::ntp_host]);
    NTP.begin(db[kk::gmt]);
}

void loop() {
    sett_tick();
    WiFiConnector.tick();
    NTP.tick();
}