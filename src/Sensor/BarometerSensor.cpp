//
// Created by sergey-athlete on 02.04.23.
//

#include "../../include/Sensor/BarometerSensor.h"

using namespace std;

int BarometerSensor::id = 0;


BarometerSensor::BarometerSensor(BarometerSensor &anotherSensor) :
    BarometerSensor(anotherSensor.getName(), anotherSensor.getLimit(),
                    anotherSensor.getSensorError()){
    setValue(anotherSensor.getValue());
}

BarometerSensor::BarometerSensor(SensorLimitations& inLimit, float inSensorError):
        BarometerSensor("SensorBarometer" + to_string(id), inLimit, inSensorError) {}

BarometerSensor::BarometerSensor(string inName, SensorLimitations &inLimit, float inSensorError)
        : Sensor(BAROMETRIC_PRESSURE_SENSOR, std::move(inName), inSensorError) {
    limit = inLimit;
    ++id;
}

void BarometerSensor::setValue(float pressurePSI) {
    unique_lock<shared_timed_mutex> lock(dataMtx);
    if(limit.getMinValue() <= pressurePSI && pressurePSI <= limit.getMaxValue()){
        value = pressurePSI;
    }else{
        /**/
    }
}

BarometerSensor::~BarometerSensor() {
    --id;
}

void BarometerSensor::setLimit(SensorLimitations &newLimit) {
    limit = newLimit;
}

