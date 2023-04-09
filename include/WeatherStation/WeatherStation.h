//
// Created by sergey-athlete on 28.03.23.
//

#ifndef MODULEWEATHERSTATION_WEATHERSTATION_H
#define MODULEWEATHERSTATION_WEATHERSTATION_H

#include "IWeatherStation.h"
#include "WeatherStationWin.h"

#include <vector>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <atomic>
#include <QCloseEvent>
#include "../../include/AlgorithmZambretti.h"



using namespace std;

class WeatherStation : public WeatherStationWin, public IWeatherStation{
private:
    AlgorithmZambretti* forecast;

    map<TypeSensor, vector<ISensor*>*> sensors;
    queue<MessageSensors*> messageQueue;

    mutex mtxMessage;
    condition_variable cv;

    std::atomic<bool> m_isEndProcess;
    std::thread* thrProcessSensors;
    std::thread* thrReadSensors;
private:
    void processingSensors() final;
    void getDataSensors() final;
    float readDataSensors(vector<ISensor*>& inSensors);
    void setValSensorsOnWin(MessageSensors& inMessage) final;

public:
    WeatherStation(vector<ISensor*>& inSensors, QWidget *parent = nullptr);
    ~WeatherStation();
};


#endif //MODULEWEATHERSTATION_WEATHERSTATION_H
