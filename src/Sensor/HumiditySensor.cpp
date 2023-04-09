//

#include <iostream>
#include "../../include/Sensor/HumiditySensor.h"

using namespace std;

int HumiditySensor::id = 0;


HumiditySensor::HumiditySensor(HumiditySensor &anotherSensor):
    HumiditySensor(anotherSensor.getName(), anotherSensor.getSensorError()) {
    setValue(anotherSensor.getValue());
}
HumiditySensor::HumiditySensor(float inSensorError) :
        HumiditySensor(("SensorHumidity" + to_string(id)), inSensorError){}

HumiditySensor::HumiditySensor(string inName, float inSensorError)
            :Sensor(HUMIDITY_SENSOR, std::move(inName), inSensorError)  {
    limit = SensorLimitations(0, 100);
    value = 0;
    ++id;
}

void HumiditySensor::setValue(float humidity) {
    unique_lock<shared_timed_mutex> lock(dataMtx);
    if(limit.getMinValue() <= humidity && humidity <= limit.getMaxValue()){
        value = humidity;
    }
}

HumiditySensor::~HumiditySensor() {
    --id;
}

