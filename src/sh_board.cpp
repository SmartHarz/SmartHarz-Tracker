/**
 * @file sh_board.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "sh_board.h"

void setupBoard()
{
    pinMode(POWER_EN_PIN, OUTPUT);
    digitalWrite(POWER_EN_PIN, HIGH);

    SERIAL_MON.begin(115200);
    SERIAL_MON.println("Start\n");
    delay(2000);

    SERIAL_MON.println("[Peripherals] Initializing ...");
    SERIAL_MON.flush();

    ledInit();

    buttonInit();

    i2cInit();

    SERIAL_MON.println("[Peripherals] Initialized");
}

void i2cInit()
{
    SERIAL_MON.println("[I2C] Initializing ...");

    Wire.setPins(SDA_PIN, SCL_PIN);
    Wire.begin();
    delay(500);

    SERIAL_MON.println("[I2C] Initialized");
}

void spiInit()
{
    SERIAL_MON.println("[SPI] Initializing ...");

    // SPI.setPins(LORA_MISO, LORA_SCLK, LORA_MOSI);
    SERIAL_MON.println("[SPI] Initialized");
}

void ledInit()
{
    SERIAL_MON.println("[LEDs] Initializing ...");

    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);

    int i = 10;
    while (i--)
    {
        digitalWrite(BLUE_LED_PIN, !digitalRead(BLUE_LED_PIN));
        digitalWrite(RED_LED_PIN, !digitalRead(RED_LED_PIN));
        digitalWrite(GREEN_LED_PIN, !digitalRead(GREEN_LED_PIN));
        delay(300);
    }

    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, HIGH);

    delay(100);

    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);

    SERIAL_MON.println("[LEDs] Initialized");
}

void buttonInit()
{
    SERIAL_MON.println("[Buttons] Initializing ...");

    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(TOUCH_PIN, INPUT_PULLUP);

    SERIAL_MON.println("[Buttons] Initialized");
}