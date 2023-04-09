//
// Created by sergey-athlete on 02.04.23.
//

#ifndef MODULEWEATHERSTATION_BAROMETERSENSOR_H
#define MODULEWEATHERSTATION_BAROMETERSENSOR_H

#include "Sensor.h"


class BarometerSensor : public Sensor{
private:
    static int id;
    using Sensor::value;
    using Sensor::limit;
    using Sensor::dataMtx;
public:
    BarometerSensor(SensorLimitations& inLimit, float inSensorError = 0.f);
    BarometerSensor(std::string inName, SensorLimitations& inLimit, float inSensorError = 0.f);
    BarometerSensor(BarometerSensor &anotherSensor);
    ~BarometerSensor();

    void setValue(float pressurePSI) final;
    void setLimit(SensorLimitations& newLimit);
};


#endif //MODULEWEATHERSTATION_BAROMETERSENSOR_H
