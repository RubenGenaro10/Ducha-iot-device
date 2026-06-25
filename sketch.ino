#include "WaterMixerDevice.h"

WaterMixerDevice device;

void setup() {

    Serial.begin(115200);

    device.begin();
}

void loop() {

    device.update();

    delay(2000);
}