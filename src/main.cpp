/**
 * @file main.cpp
 * @author SmartHarz (info@smartharz.de)
 * @brief
 * @version 0.1
 * @date 2022-05-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "main.h"

int      x    = 0;
uint32_t last = 0;

void     setup()
{
    SERIAL_MON.begin(115200);
    SERIAL_MON.println("Start\n");
    delay(2000);

    setupBoard();

#ifdef BME280
    setupBME280();
#endif

    setupGPS();

    delay(1000);

    SERIAL_MON.println("Setup finished...");
}

void loop()
{
    while (SERIAL_GPS.available() > 0)
        gps->encode(SERIAL_GPS.read());

    if (millis() - last > 5000)
    {
        if (gps->location.isUpdated())
        {
            SERIAL_MON.print(F("LOCATION   Fix Age="));
            SERIAL_MON.print(gps->location.age());
            SERIAL_MON.print(F("ms Raw Lat="));
            SERIAL_MON.print(gps->location.rawLat().negative ? "-" : "+");
            SERIAL_MON.print(gps->location.rawLat().deg);
            SERIAL_MON.print("[+");
            SERIAL_MON.print(gps->location.rawLat().billionths);
            SERIAL_MON.print(F(" billionths],  Raw Long="));
            SERIAL_MON.print(gps->location.rawLng().negative ? "-" : "+");
            SERIAL_MON.print(gps->location.rawLng().deg);
            SERIAL_MON.print("[+");
            SERIAL_MON.print(gps->location.rawLng().billionths);
            SERIAL_MON.print(F(" billionths],  Lat="));
            SERIAL_MON.print(gps->location.lat(), 6);
            SERIAL_MON.print(F(" Long="));
            SERIAL_MON.println(gps->location.lng(), 6);
        }

        if (gps->date.isUpdated())
        {
            SERIAL_MON.print(F("DATE       Fix Age="));
            SERIAL_MON.print(gps->date.age());
            SERIAL_MON.print(F("ms Raw="));
            SERIAL_MON.print(gps->date.value());
            SERIAL_MON.print(F(" Year="));
            SERIAL_MON.print(gps->date.year());
            SERIAL_MON.print(F(" Month="));
            SERIAL_MON.print(gps->date.month());
            SERIAL_MON.print(F(" Day="));
            SERIAL_MON.println(gps->date.day());
        }

        if (gps->time.isUpdated())
        {
            SERIAL_MON.print(F("TIME       Fix Age="));
            SERIAL_MON.print(gps->time.age());
            SERIAL_MON.print(F("ms Raw="));
            SERIAL_MON.print(gps->time.value());
            SERIAL_MON.print(F(" Hour="));
            SERIAL_MON.print(gps->time.hour());
            SERIAL_MON.print(F(" Minute="));
            SERIAL_MON.print(gps->time.minute());
            SERIAL_MON.print(F(" Second="));
            SERIAL_MON.print(gps->time.second());
            SERIAL_MON.print(F(" Hundredths="));
            SERIAL_MON.println(gps->time.centisecond());
        }

        if (gps->speed.isUpdated())
        {
            SERIAL_MON.print(F("SPEED      Fix Age="));
            SERIAL_MON.print(gps->speed.age());
            SERIAL_MON.print(F("ms Raw="));
            SERIAL_MON.print(gps->speed.value());
            SERIAL_MON.print(F(" Knots="));
            SERIAL_MON.print(gps->speed.knots());
            SERIAL_MON.print(F(" MPH="));
            SERIAL_MON.print(gps->speed.mph());
            SERIAL_MON.print(F(" m/s="));
            SERIAL_MON.print(gps->speed.mps());
            SERIAL_MON.print(F(" km/h="));
            SERIAL_MON.println(gps->speed.kmph());
        }

        if (gps->course.isUpdated())
        {
            SERIAL_MON.print(F("COURSE     Fix Age="));
            SERIAL_MON.print(gps->course.age());
            SERIAL_MON.print(F("ms Raw="));
            SERIAL_MON.print(gps->course.value());
            SERIAL_MON.print(F(" Deg="));
            SERIAL_MON.println(gps->course.deg());
        }

        if (gps->altitude.isUpdated())
        {
            SERIAL_MON.print(F("ALTITUDE   Fix Age="));
            SERIAL_MON.print(gps->altitude.age());
            SERIAL_MON.print(F("ms Raw="));
            SERIAL_MON.print(gps->altitude.value());
            SERIAL_MON.print(F(" Meters="));
            SERIAL_MON.print(gps->altitude.meters());
            SERIAL_MON.print(F(" Miles="));
            SERIAL_MON.print(gps->altitude.miles());
            SERIAL_MON.print(F(" KM="));
            SERIAL_MON.print(gps->altitude.kilometers());
            SERIAL_MON.print(F(" Feet="));
            SERIAL_MON.println(gps->altitude.feet());
        }

        if (gps->satellites.isUpdated())
        {
            SERIAL_MON.print(F("SATELLITES Fix Age="));
            SERIAL_MON.print(gps->satellites.age());
            SERIAL_MON.print(F("ms Value="));
            SERIAL_MON.println(gps->satellites.value());
        }

        if (gps->hdop.isUpdated())
        {
            SERIAL_MON.print(F("HDOP       Fix Age="));
            SERIAL_MON.print(gps->hdop.age());
            SERIAL_MON.print(F("ms Value="));
            SERIAL_MON.println(gps->hdop.value());
        }

        if (gps->charsProcessed() < 10)
            Serial.println(F("WARNING: No GPS data.  Check wiring."));
        last = millis();
        Serial.println();
    }

    SERIAL_MON.println();

    // /* Get BME sensor data */
    // getEnvironmentalData();

    delay(500);

    delay(2500);
}
