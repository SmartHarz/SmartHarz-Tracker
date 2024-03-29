/**
 * @file credentials_template.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _CREDENTIALS_H_
#define _CREDENTIALS_H_


#include <lmic.h>
#include <avr/pgmspace.h>

/**
 * This EUI must be in little-endian format, so least-significant-byte
 * first. When copying an EUI from ttnctl output, this means to reverse
 * the bytes. For TTN issued EUIs the last bytes should be 0xD5, 0xB3,
 * 0x70.
 */
static const u1_t PROGMEM DEVEUI[8]={ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8);}

/** This should also be in little endian format, see above. */
static const u1_t PROGMEM APPEUI[8]={ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8);}

/**
 * This key should be in big endian format (or, since it is not really a
 * number but a block of memory, endianness does not really apply). In
 * practice, a key taken from ttnctl can be copied as-is.
 */
static const u1_t PROGMEM APPKEY[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
void os_getDevKey (u1_t* buf) { memcpy_P(buf, APPKEY, 16);}

#endif // _CREDENTIALS_H_