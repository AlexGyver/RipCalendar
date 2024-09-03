#pragma once
#include <GyverDBFile.h>
#include <LittleFS.h>

DB_KEYS(
    kk,
    wifi_ssid,
    wifi_pass,
    gmt,
    geo_lat,
    geo_lon,
    ntp_host,
    time0,
    time1,
    time2,
    time3,
    print_time,
    ttl_mode,
    turn180

);

GyverDBFile db(&LittleFS, "settings.db");

void db_init() {
    LittleFS.begin();
    db.begin();

    db.init(kk::wifi_ssid, "");
    db.init(kk::wifi_pass, "");
    db.init(kk::gmt, 3);
    db.init(kk::geo_lat, 55.0);
    db.init(kk::geo_lon, 37.0);
    db.init(kk::ntp_host, "pool.ntp.org");
    db.init(kk::time0, 6);
    db.init(kk::time1, 12);
    db.init(kk::time2, 18);
    db.init(kk::time3, 23);
    db.init(kk::print_time, DaySeconds(8, 0, 0).seconds);
    db.init(kk::ttl_mode, false);
    db.init(kk::turn180, false);
}