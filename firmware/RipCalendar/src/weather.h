#pragma once
#include <GSON.h>
#include <GyverHTTP.h>

class Weather {
   public:
    // получить погоду по широте и долготе
    bool get(float lat, float lon) {
        String url = F("/v1/forecast?latitude=");
        url += String(lat, 4);
        url += F("&longitude=");
        url += String(lon, 4);
        url += F("&hourly=apparent_temperature,weather_code,wind_speed_10m&wind_speed_unit=ms&timeformat=unixtime&timezone=auto&forecast_days=1");

        ghttp::EspInsecureClient http("api.open-meteo.com", 443);
        if (http.request(url)) {
            ghttp::Client::Response resp = http.getResponse();
            if (resp) {
                String s = resp.body().readString();
                gson::Parser json;
                if (json.parse(s)) {
                    json["hourly"]["apparent_temperature"].parseTo(temps);
                    json["hourly"]["wind_speed_10m"].parseTo(winds);
                    json["hourly"]["weather_code"].parseTo(codes);
                    // json["hourly"].stringify(Serial);
                    // for (int i = 0; i < 24; i++) {
                    //     Serial.print(temps[i]);
                    //     Serial.print('\t');
                    //     Serial.print(winds[i]);
                    //     Serial.print('\t');
                    //     Serial.print(codes[i]);
                    //     Serial.println();
                    // }
                    // Serial.println();
                    return true;
                } else {
                    Serial.println("parse error");
                }
            } else {
                Serial.println("response error");
            }
        } else {
            Serial.println("connect error");
        }
        return false;
    }

    // t0..t1 утро, t1.. t2 день, t2.. t3 вечер
    void calcRange(int t0, int t1, int t2, int t3) {
        _calc(t0, t1, 0);
        _calc(t1, t2, 1);
        _calc(t2, t3, 2);
        // Serial.println("t.min\tt.max\twnd.min\tcode.max");
        // for (int i = 0; i < 3; i++) {
        //     Serial.print(temp_min[i]);
        //     Serial.print('\t');
        //     Serial.print(temp_max[i]);
        //     Serial.print('\t');
        //     Serial.print(wind_mid[i]);
        //     Serial.print('\t');
        //     Serial.print(code_max[i]);
        //     Serial.println();
        // }
    }

    float temps[24];
    float winds[24];
    uint8_t codes[24];

    int8_t temp_min[3];
    int8_t temp_max[3];
    int8_t wind_mid[3];
    uint8_t code_max[3];

   private:
    void _calc(int t0, int t1, int idx) {
        wind_mid[idx] = 0;
        code_max[idx] = 0;
        temp_min[idx] = 100;
        temp_max[idx] = -100;

        for (int t = t0; t < t1; t++) {
            wind_mid[idx] += winds[t];
            code_max[idx] = max(code_max[idx], codes[t]);

            int8_t temp = round(temps[t]);
            temp_min[idx] = min(temp_min[idx], temp);
            temp_max[idx] = max(temp_max[idx], temp);
        }
        wind_mid[idx] /= (t1 - t0);
    }
};