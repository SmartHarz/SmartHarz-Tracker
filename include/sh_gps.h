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
#include "utilities.h"
#include <TinyGPS++.h>

extern TinyGPSPlus *gps;

extern float        latitude, longitude, altitude;
extern int          hdop, sats;

/** Function prototypes **/
void setupGPS();

#endif // _SH_GPS_H_
