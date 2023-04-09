//
// Created by sergey-athlete on 02.04.23.
//

#ifndef MODULEWEATHERSTATION_TEMPERATURESENSORWIN_H
#define MODULEWEATHERSTATION_TEMPERATURESENSORWIN_H

#include "SensorWindow.h"
#include "../TemperatureSensor.h"

class TemperatureSensorWin: public SensorWindow, public TemperatureSensor{
private:
    void initGui() final;
public:
    TemperatureSensorWin(TemperatureSensor &anotherSensor, QWidget* parent = nullptr);
    TemperatureSensorWin(SensorLimitations& newLimit, float inSensorError = 0.f, QWidget* parent = nullptr);
    TemperatureSensorWin(std::string newName, SensorLimitations& newLimit,
                         float inSensorError = 0.f, QWidget* parent = nullptr);
    ~TemperatureSensorWin(){};
private slots:
    void updateSlider(double position) override;
    void updateValueSensor() override;
};


#endif //MODULEWEATHERSTATION_TEMPERATURESENSORWIN_H
