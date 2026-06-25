#pragma once

#include <DHT.h>
#include "Sensor.h"

class DHTTemperatureSensor : public Sensor {

private:
    DHT dht;

public:

    DHTTemperatureSensor(int pin)
        : dht(pin, DHT22) {}

    void begin() override {
        dht.begin();
    }

    float readTemperature() {
        return dht.readTemperature();
    }
};