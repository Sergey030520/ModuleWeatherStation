//
// Created by sergey-athlete on 02.04.23.
//

#ifndef MODULEWEATHERSTATION_HUMIDITYSENSORWIN_H
#define MODULEWEATHERSTATION_HUMIDITYSENSORWIN_H

#include "SensorWindow.h"
#include "../HumiditySensor.h"

class HumiditySensorWin: public SensorWindow, public HumiditySensor{
private:
    void initGui() override final;

public:
    HumiditySensorWin(float inSensorError = 0.f, QWidget* parent = nullptr);
    HumiditySensorWin(std::string newName, float inSensorError = 0.f, QWidget *parent = nullptr);
    HumiditySensorWin(HumiditySensor &anotherSensor, QWidget* parent = nullptr);
    ~HumiditySensorWin(){};
private slots:
    void updateSlider(double position) override;
    void updateValueSensor() override;
};


#endif //MODULEWEATHERSTATION_HUMIDITYSENSORWIN_H
