//
// Created by sergey-athlete on 03.04.23.
//

#ifndef MODULEWEATHERSTATION_IWEATHERSTATION_H
#define MODULEWEATHERSTATION_IWEATHERSTATION_H

#include <future>
#include <thread>
#include <map>
#include "../Sensor/ISensor.h"

typedef  std::map<TypeSensor, float> MessageSensors;

class IWeatherStation{
public:
    virtual void processingSensors() = 0;
    virtual void getDataSensors() = 0;
    virtual void setValSensorsOnWin(MessageSensors&) = 0;
    virtual ~IWeatherStation(){};
};

#endif //MODULEWEATHERSTATION_IWEATHERSTATION_H
