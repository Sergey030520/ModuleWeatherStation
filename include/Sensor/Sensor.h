//
// Created by sergey-athlete on 02.04.23.
//

#ifndef MODULEWEATHERSTATION_SENSOR_H
#define MODULEWEATHERSTATION_SENSOR_H

#include "ISensor.h"
#include <queue>
#include <shared_mutex>
#include <condition_variable>

class Sensor : public ISensor{
private:
    std::string name;
    float sensorError;
    TypeSensor type;

protected:
    SensorLimitations limit;
    float value;
    std::shared_timed_mutex dataMtx;

public:
    Sensor(TypeSensor inType, std::string inName = "sensor", float inSensorError = 0.f);

    TypeSensor getType() const final;
    float getValue() final;

    void setName(std::string newName) override;
    std::string getName() final;

    float getSensorError() final;
    SensorLimitations& getLimit() final;

    virtual ~Sensor(){};
};


#endif //MODULEWEATHERSTATION_SENSOR_H
