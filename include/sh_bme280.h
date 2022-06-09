/**
 * @file sh_bme280.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _SH_BME280_H_
#define _SH_BME280_H_

#if defined BME280
#include "configuration.h"
#include "t-echo.h"
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

/** Variables **/
extern Adafruit_BME280 bme;
extern float           temperature, humidity, pressure;

/** Function Prototypes **/
void setupBME280();
void getEnvironmentalData();

#endif // defined BME280
#endif // _SH_BME280_H_
