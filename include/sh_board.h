/**
 * @file t-echo.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef _SH_BOARD_H_
#define _SH_BOARD_H_

/*** Includes ***/
#include "configuration.h"
#include "t-echo.h"
#include <SPI.h>
#include <Wire.h>

/*** Variables ***/
extern bool  isBatteryConnect;
extern float batteryVoltage;
const float  maxBattVoltage  = 4.2;
const int    minBatteryLevel = 3000;

/*** Function prototypes ***/
void  setupBoard();
void  i2cInit();
void  spiInit();
void  ledInit();
void  buttonInit();
bool  checkBattery();
float getBatteryVoltage();
int   getBatteryLevel();

#endif // _SH_BOARD_H_
