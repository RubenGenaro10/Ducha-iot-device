#pragma once

#include "EventHandler.h"
#include "CommandHandler.h"

#include "DHTTemperatureSensor.h"
#include "PotentiometerFlowSensor.h"
#include "LCDDisplay.h"

class WaterMixerDevice :
    public EventHandler,
    public CommandHandler {

private:
 DHTTemperatureSensor coldTemp;
    DHTTemperatureSensor hotTemp;

    PotentiometerFlowSensor coldFlow;
    PotentiometerFlowSensor hotFlow;

    LCDDisplay display;

    float tCold;
    float tHot;
    float qCold;
    float qHot;

    float currentMixTemperature;

public:

    WaterMixerDevice()
        : coldTemp(4),
          hotTemp(15),
          coldFlow(34),
          hotFlow(35)
    {}

    void begin();

    void update();

    void onTemperatureRead() override;

    void executeMixCalculation() override;

    void printStatus();
};