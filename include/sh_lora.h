/**
 * @file sh_lora.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _SH_LORA_H_
#define _SH_LORA_H_

#include "credentials.h"
#include <hal/hal.h>
#include <lmic.h>

#include "t-echo.h"
#include <hal/hal.h>
#include <lmic.h>

/*** LoRa setup ***/
/* TX scheduler */
const unsigned TX_INTERVAL = 60;

/* Pin mapping */
// clang-format off
const lmic_pinmap lmic_pins =
{
    .nss = LORA_CS,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = LORA_RST,
    .dio = {LORA_DIO0, LORA_DIO0, LMIC_UNUSED_PIN}
};
// clang-format on

/** Function prototypes **/
bool loraInit();

#endif // _SH_LORA_H_