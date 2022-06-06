/**
 * @file sh_bme280.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "configuration.h"

#if defined BME280
#include "sh_bme280.h"

void setupBME280()
{
    SERIAL_MON.println("[BME280] Initializing ...");

    SERIAL_MON.println(bme.begin());
    // if (!bme.begin())
    // {
    //     SERIAL_MON.println("[BME280] Missing, check configuration ...");
    //     while (1)
    //         delay(10);
    // }

    SERIAL_MON.println("[BME280] Setting forced mode and sampling rate ...");

    // clang-format off
    bme.setSampling(Adafruit_BME280::MODE_FORCED,
                    Adafruit_BME280::SAMPLING_X16,
                    Adafruit_BME280::SAMPLING_X16,
                    Adafruit_BME280::SAMPLING_X16,
                    Adafruit_BME280::FILTER_OFF,
                    Adafruit_BME280::STANDBY_MS_0_5);
    // clang-format on

    SERIAL_MON.println("[BME280] Initialized");
}

/**
 * @brief Get the Environmental Data object
 *
 */
void getEnvironmentalData()
{
    bme.takeForcedMeasurement();
    temperature = bme.readTemperature();
    humidity    = bme.readHumidity();
    pressure    = bme.readPressure();
}

#endif
