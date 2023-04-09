//
// Created by sergey-athlete on 02.04.23.
//

#include "../../include/Sensor/Sensor.h"
#include <shared_mutex>

Sensor::Sensor(TypeSensor inTypeSensor, std::string inName, float inSensorError)
            : type(inTypeSensor), name(std::move(inName)), sensorError(inSensorError), value(0){}

TypeSensor Sensor::getType() const {
    return type;
}

void Sensor::setName(std::string newName) {
    name = std::move(newName);
}

std::string Sensor::getName() {
    return name;
}

float Sensor::getSensorError() {
    return sensorError;
}

SensorLimitations &Sensor::getLimit() {
    return limit;
}

float Sensor::getValue() {
    std::shared_lock<std::shared_timed_mutex> lock(dataMtx);
    return value;
}




