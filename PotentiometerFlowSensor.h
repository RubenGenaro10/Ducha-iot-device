#pragma once

#include "Sensor.h"

class PotentiometerFlowSensor : public Sensor {

private:
    int pin;

public:

    PotentiometerFlowSensor(int pin)
        : pin(pin) {}

    void begin() override {}

    float readFlow() {

        int value = analogRead(pin);

        return map(value, 0, 4095, 40, 160) / 10.0;
    }
};