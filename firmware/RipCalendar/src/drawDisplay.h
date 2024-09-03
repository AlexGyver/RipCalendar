#pragma once
#include <Arduino.h>
#include <BufferGFX.h>
#include <GyverNTP.h>
#include <Stamp.h>

#include "db.h"
#include "fonts/ubuntub_150.h"
#include "fonts/ubuntuc_16.h"
#include "fonts/ubuntum_18.h"
#include "fonts/ubuntum_22.h"
#include "icons.h"
#include "printer.h"
#include "text/holidays.h"
#include "text/lang.h"
#include "weather.h"

void drawIcon(GyverGFX& gfx, int x, int y, uint8_t code) {
    uint8_t* index_p = (uint8_t*)memchr(icons_index_index, code, sizeof(icons_index_index));
    if (index_p) {
        int index = index_p - icons_index_index;
        gfx.drawImage(x, y, icons_index[index]);
    }
}

void drawNumbers(GyverGFX& gfx, int cx, int y, int8_t tmin, int8_t tmax, int8_t wind) {
    String s;
    if (tmin > 0) s += '+';
    s += tmin;
    s += ".. ";
    if (tmax > 0) s += '+';
    s += tmax;
    gfx.setFont(ubuntum_18);
    uint16_t w = gfx.textWidth(s);
    gfx.setCursor(cx - w / 2, y);
    gfx.println(s);

    s = "";
    s += wind;
    s += " м/с";
    w = gfx.textWidth(s);
    gfx.setCursorX(cx - w / 2);
    gfx.print(s);
}

void drawWeather(GyverGFX& gfx, int8_t* temp_min, int8_t* temp_max, int8_t* wind_mid, uint8_t* code_max) {
    Datime dt(NTP);
    uint16_t gw = gfx.width();
    String s;
    uint16_t w;
    uint16_t curY = 0;

    // day
    gfx.setFont(ubuntub_150);
    s = dt.day;
    w = gfx.textWidth(s);
    gfx.setCursor(gw / 2 - w / 2, curY);
    gfx.print(s);

    // month weekday
    gfx.setFont(ubuntum_22);
    s = "";
    s += months_list[dt.month - 1].f_str();
    s += ", ";
    s += weekdays_list[dt.weekDay - 1].f_str();
    w = gfx.textWidth(s);
    curY = ubuntub_150.lineHeight + 5;
    gfx.setCursor(gw / 2 - w / 2, curY);
    gfx.print(s);
    curY += ubuntum_22.lineHeight + 8;

    // line
    gfx.lineH(curY, 0, gw - 1, 3);
    curY += 5;

    // holidays
    gfx.setFont(ubuntuc_16);
    gfx.setCursor(0, curY);
    gfx.println(holidays_list[dt.dayIndex()]);
    curY = gfx.getCursorY() + 10;

    // rects
    int strokew = 3;
    int radius = 10;
    int rectw = gw / 3 - strokew * 2;
    int recth = 190;
    gfx.roundRectWH((gw - rectw) / 2, curY, rectw, recth, radius, GFX_STROKE, strokew);
    gfx.roundRectWH(strokew, curY, rectw, recth, radius, GFX_STROKE, strokew);
    gfx.roundRectWH(gw - (rectw + strokew), curY, rectw, recth, radius, GFX_STROKE, strokew);

    // icons & info
    int cx[3];
    cx[0] = strokew + rectw / 2;
    cx[1] = gw / 2;
    cx[2] = gw - cx[0];
    int imgw2 = 128 / 2;

    for (int i = 0; i < 3; i++) {
        drawIcon(gfx, cx[i] - imgw2, curY, code_max[i]);
        drawNumbers(gfx, cx[i], curY + 128, temp_min[i], temp_max[i], wind_mid[i]);
    }
}

void requestAndPrint() {
    Weather w;
    w.get(db[kk::geo_lat], db[kk::geo_lon]);
    w.calcRange(db[kk::time0], db[kk::time1], db[kk::time2], db[kk::time3]);

    BufferGFX gfx(384, 450);
    if (db[kk::turn180]) gfx.setRotation(2);
    drawWeather(gfx, w.temp_min, w.temp_max, w.wind_mid, w.code_max);
    printer.printBuffer(gfx, db[kk::ttl_mode]);
    printer.feed(2);
}