/**
 * @file sh_board.h
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
#include "utilities.h"
#include <SPI.h>
#include <Wire.h>

/*** Function prototypes ***/
void setupBoard();
void i2cInit();
void spiInit();
void ledInit();
void buttonInit();

#endif // _SH_BOARD_H_
