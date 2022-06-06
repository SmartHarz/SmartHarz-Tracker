/**
 * @file sh_gps.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sh_gps.h"

void setupGPS()
{
    SERIAL_MON.println("[GPS] Initializing ...");

    SERIAL_GPS.setPins(GPS_RX_PIN, GPS_TX_PIN);
    SERIAL_GPS.begin(4800);
    delay(250);
    SERIAL_GPS.write("$PCAS01,1*1D\r\n");
    delay(250);
    SERIAL_GPS.end();
    delay(250);
    SERIAL_GPS.begin(9600);
    delay(250);

    // pinMode(GPS_PPS_PIN, INPUT);

    pinMode(GPS_WAKEUP_PIN, OUTPUT);
    digitalWrite(GPS_WAKEUP_PIN, HIGH);

    delay(10);
    pinMode(GPS_RESET_PIN, OUTPUT);
    digitalWrite(GPS_RESET_PIN, HIGH);
    delay(10);
    digitalWrite(GPS_RESET_PIN, LOW);
    delay(10);
    digitalWrite(GPS_RESET_PIN, HIGH);
    gps = new TinyGPSPlus();

    delay(500);

    SERIAL_MON.println("[GPS] Initialized ...");
}
