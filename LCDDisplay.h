#pragma once

#include <LiquidCrystal_I2C.h>
#include "Actuator.h"

class LCDDisplay : public Actuator {

private:
    LiquidCrystal_I2C lcd;

public:

    LCDDisplay()
        : lcd(0x27,16,2) {}

    void begin() override {

        lcd.init();
        lcd.backlight();
    }

    void showTemperature(float mixTemp) {

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("Mix Temp:");

        lcd.setCursor(0,1);
        lcd.print(mixTemp);
        lcd.print(" C");
    }
};