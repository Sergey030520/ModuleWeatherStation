//
// Created by sergey-athlete on 02.04.23.
//

#ifndef MODULEWEATHERSTATION_HUMIDITYSENSOR_H
#define MODULEWEATHERSTATION_HUMIDITYSENSOR_H

#include "Sensor.h"

class HumiditySensor : public Sensor{
private:
    static int id;
    using Sensor::value;
    using Sensor::limit;
    using Sensor::dataMtx;
public:
    HumiditySensor(float inSensorError = 0.f);
    HumiditySensor(std::string inName, float inSensorError = 0.f);
    HumiditySensor(HumiditySensor &anotherSensor);
    ~HumiditySensor();

    void setValue(float humidity) final;
};


#endif //MODULEWEATHERSTATION_HUMIDITYSENSOR_H
