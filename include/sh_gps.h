/**
 * @file sh_gps.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _SH_GPS_H_
#define _SH_GPS_H_

#include "configuration.h"
#include "t-echo.h"
#include <TinyGPS++.h>

extern TinyGPSPlus *gps;

/*** Variables ***/

extern float latitude, longitude, altitude;
extern int   hdop, sats;
extern bool  hasGPSFix;

/*** Function prototypes ***/
void setupGPS();

#endif // _SH_GPS_H_
