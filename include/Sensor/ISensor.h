//
// Created by sergey-athlete on 27.03.23.
//

#ifndef MODULEWEATHERSTATION_ISENSOR_H
#define MODULEWEATHERSTATION_ISENSOR_H

#include <map>
#include <string>
#include <utility>
#include <iostream>


class SensorLimitations{
private:
    float maxValue;
    float minValue;
public:
    SensorLimitations() : minValue(0), maxValue(0){};
    SensorLimitations(float min, float  max) : minValue(min), maxValue(max){
        if(maxValue < minValue){
            std::swap(maxValue, minValue);
        }
    }
    float getMaxValue() const{
        return maxValue;
    }
    float getMinValue() const{
        return minValue;
    }
};
enum TypeSensor {
    TEMPERATURE_SENSOR, HUMIDITY_SENSOR, BAROMETRIC_PRESSURE_SENSOR
};


class ISensor {
public:
    virtual TypeSensor getType() const = 0;

    virtual void setValue(float newValue) = 0;
    virtual float getValue() = 0;

    virtual SensorLimitations& getLimit() = 0;

    virtual void setName(std::string name) = 0;
    virtual std::string getName() = 0;

    virtual float getSensorError() = 0;

    virtual ~ISensor(){};
};


#endif //MODULEWEATHERSTATION_ISENSOR_H
