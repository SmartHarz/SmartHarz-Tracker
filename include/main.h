/**
 * @file main.h
 * @author SmartHarz (info@smartharz.de)
 * @brief
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */

/*** General includes ***/
#include <Arduino.h>

/*** Board setup ***/
#include "configuration.h"
#include "sh_board.h"
#include "utilities.h"

/*** LoRa setup ***/
// #include "sh_lora.h"

/*** BME280 setup ***/
#include "sh_bme280.h"
Adafruit_BME280 bme;
float           temperature, humidity, pressure;

/*** E-paper setup ***/
// #include "sh_epd.h"

/*** GPS setup ***/
#include "sh_gps.h"
TinyGPSPlus *gps;
float        latitude, longitude, altitude;
int          hdop, sats;
