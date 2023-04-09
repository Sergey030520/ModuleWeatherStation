//
// Created by sergey-athlete on 02.04.23.
//

#ifndef MODULEWEATHERSTATION_BAROMETERSENSORWIN_H
#define MODULEWEATHERSTATION_BAROMETERSENSORWIN_H

#include "SensorWindow.h"
#include "../BarometerSensor.h"

class BarometerSensorWin : public SensorWindow, public BarometerSensor{
private:
    void initGui() final;
public:
    BarometerSensorWin(BarometerSensor &sensor, QWidget* parent = nullptr);
    BarometerSensorWin(SensorLimitations& inLimit, float inSensorError = 0.f, QWidget* parent = nullptr);
    BarometerSensorWin(std::string inName, SensorLimitations& inLimit,
                       float inSensorError = 0.f, QWidget* parent = nullptr);
    ~BarometerSensorWin(){};

private slots:
    void updateSlider(double position) override;
    void updateValueSensor() override;
};


#endif //MODULEWEATHERSTATION_BAROMETERSENSORWIN_H
