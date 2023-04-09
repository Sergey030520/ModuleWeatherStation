//
// Created by sergey-athlete on 27.03.23.
//

#ifndef MODULEWEATHERSTATION_TEMPERATURESENSOR_H
#define MODULEWEATHERSTATION_TEMPERATURESENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor{
private:
    static int id;
    using Sensor::value;
    using Sensor::limit;
    using Sensor::dataMtx;
public:
    TemperatureSensor(SensorLimitations& newLimit, float inSensorError = 0.f);
    TemperatureSensor(std::string inName, SensorLimitations& inLimit, float inSensorError = 0.f);
    TemperatureSensor(TemperatureSensor &anotherSensor);
    ~TemperatureSensor();

    void setValue(float tempC) final;
    void setLimit(SensorLimitations& newLimit);

    static float convertToFahrenheit(float tempC);
    static float convertToCelsius(float tempF);

};


#endif //MODULEWEATHERSTATION_TEMPERATURESENSOR_H
