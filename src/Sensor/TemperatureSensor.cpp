//
// Created by sergey-athlete on 27.03.23.
//


#include <iostream>
#include "../../include/Sensor/TemperatureSensor.h"

using namespace std;

int TemperatureSensor::id = 0;


TemperatureSensor::TemperatureSensor(TemperatureSensor &anotherSensor) :
    TemperatureSensor(anotherSensor.getName(), anotherSensor.getLimit(),
                      anotherSensor.getSensorError()){
    setValue(anotherSensor.getValue());
}

TemperatureSensor::TemperatureSensor(SensorLimitations& newLimit, float inSensorError):
        TemperatureSensor("SensorTemperature" + to_string(id++), newLimit,
                          inSensorError){}

TemperatureSensor::TemperatureSensor(string inName, SensorLimitations& inLimit, float inSensorError)
        : Sensor(TEMPERATURE_SENSOR, std::move(inName), inSensorError) {
    limit = inLimit;
    ++id;
}

TemperatureSensor::~TemperatureSensor() {
    --id;
}

void TemperatureSensor::setValue(float tempC) {
    unique_lock<shared_timed_mutex> lock(dataMtx);
    if(tempC >= limit.getMinValue() && tempC <= limit.getMaxValue()){
        value = tempC;
    }
    else{
        /**/
    }
}


float TemperatureSensor::convertToFahrenheit(float tempC) {
    return ((9*tempC)/5)+32;
}

float TemperatureSensor::convertToCelsius(float tempF) {
    return (tempF - 32.f) * (5.f/9.f);
}

void TemperatureSensor::setLimit(SensorLimitations &newLimit) {
    limit = newLimit;
}
