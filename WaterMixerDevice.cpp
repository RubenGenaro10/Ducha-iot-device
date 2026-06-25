#include "WaterMixerDevice.h"

void WaterMixerDevice::begin() {

    coldTemp.begin();
    hotTemp.begin();

    coldFlow.begin();
    hotFlow.begin();

    display.begin();
}

void WaterMixerDevice::update() {

    onTemperatureRead();

    executeMixCalculation();

    printStatus();

    display.showTemperature(
        currentMixTemperature
    );
}

void WaterMixerDevice::onTemperatureRead() {

    Serial.println(
        "Temperature Event Received"
    );
}

void WaterMixerDevice::executeMixCalculation() {

    tCold = constrain(
        coldTemp.readTemperature(),
        1,
        20
    );

    tHot = constrain(
        hotTemp.readTemperature(),
        55,
        65
    );

    qCold = coldFlow.readFlow();
    qHot = hotFlow.readFlow();

    currentMixTemperature =
        ((qHot * tHot) + (qCold * tCold))
        / (qHot + qCold);
}

void WaterMixerDevice::printStatus() {

    Serial.println("==============");

    Serial.print("T Frio: ");
    Serial.print(tCold);
    Serial.println(" C");

    Serial.print("T Caliente: ");
    Serial.print(tHot);
    Serial.println(" C");

    Serial.print("Q Frio: ");
    Serial.print(qCold);
    Serial.println(" L/min");

    Serial.print("Q Caliente: ");
    Serial.print(qHot);
    Serial.println(" L/min");

    Serial.print("T Mix: ");
    Serial.print(currentMixTemperature);
    Serial.println(" C");

    Serial.println("==============");
}