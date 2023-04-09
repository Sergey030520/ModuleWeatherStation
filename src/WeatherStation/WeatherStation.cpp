//
// Created by sergey-athlete on 28.03.23.
//

#include "../../include/WeatherStation/WeatherStation.h"
#include <QTime>
#include <QFontDatabase>
#include <chrono>

WeatherStation::WeatherStation(vector<ISensor*>& inSensors, QWidget *parent) : WeatherStationWin(parent),
    m_isEndProcess(false){
    forecast = new AlgorithmZambretti(800, 200, 155);
    for(auto sensor : inSensors){
        if(sensors.find(sensor->getType()) == sensors.end()){
            sensors.insert(make_pair(sensor->getType(), new vector<ISensor*>()));
        }
        sensors[sensor->getType()]->push_back(sensor);
    }
    thrProcessSensors = new std::thread(&WeatherStation::processingSensors, this);
    thrReadSensors = new std::thread(&WeatherStation::getDataSensors, this);
}

WeatherStation::~WeatherStation() {
    m_isEndProcess = true;
    thrReadSensors->join();
    thrProcessSensors->join();
    delete thrReadSensors;
    delete thrProcessSensors;
    for(auto sensorsGroup : sensors){
        for(auto sensor : *sensorsGroup.second){
            delete sensor;
        }
        delete sensorsGroup.second;
    }
    while(!messageQueue.empty()){
        auto message = messageQueue.front();
        delete message;
        messageQueue.pop();
    }
}

void WeatherStation::processingSensors() {
    while(true){
        std::unique_lock<std::mutex> lock(mtxMessage);
        cv.wait(lock, [this](){
            return !messageQueue.empty() || m_isEndProcess;
        });
        if(m_isEndProcess) break;
        auto message = messageQueue.front();
        messageQueue.pop();

        lock.unlock();
        setValSensorsOnWin(*message);
        delete message;
    }
}

void WeatherStation::getDataSensors() {
    while(true) {
        auto dataSensors = new MessageSensors;

        for(auto value : sensors){
            dataSensors->insert(make_pair(value.first, readDataSensors(*value.second)));
        }

        unique_lock<mutex> lock(mtxMessage);
        messageQueue.push(dataSensors);
        cv.notify_one();
        lock.unlock();

        if(m_isEndProcess) break;

        this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

float WeatherStation::readDataSensors(vector<ISensor*> &inSensors) {
    float minValue = INT16_MAX;
    for (auto sensor: inSensors) {
        auto valueSensor = sensor->getValue();
        if (valueSensor < minValue) {
            minValue = valueSensor;
        }
    }
    return minValue;
}

void WeatherStation::setValSensorsOnWin(MessageSensors &inMessage) {
    Season season = AlgorithmZambretti::getSeasonByMonth(QDate::currentDate().month());
    auto temp = (inMessage.find(TEMPERATURE_SENSOR) != inMessage.end() ?
            QString().number(inMessage[TEMPERATURE_SENSOR], 'f',2) : nullptr);
    auto barometer = (inMessage.find(BAROMETRIC_PRESSURE_SENSOR) != inMessage.end() ?
                 QString().number(inMessage[BAROMETRIC_PRESSURE_SENSOR], 'f',2) : nullptr);
    auto humidity = (inMessage.find(HUMIDITY_SENSOR) != inMessage.end() ?
                 QString().number(inMessage[HUMIDITY_SENSOR], 'f',2) : nullptr);

    sensorsValue[TEMPERATURE_SENSOR]->setText(temp);
    sensorsValue[BAROMETRIC_PRESSURE_SENSOR]->setText(barometer);
    sensorsValue[HUMIDITY_SENSOR]->setText(humidity);

    auto resForecast = forecast->engine(inMessage[TypeSensor::BAROMETRIC_PRESSURE_SENSOR],
                                        inMessage[TypeSensor::TEMPERATURE_SENSOR], season);
    auto weatherIcon = AlgorithmZambretti::forecastProcessing(resForecast,
                                                              inMessage[TEMPERATURE_SENSOR]);

    imgWeather->setPixmap(QPixmap(weatherIcon.pathToImage.c_str()));
    weatherLabel->setText(weatherIcon.weather.c_str());
}
