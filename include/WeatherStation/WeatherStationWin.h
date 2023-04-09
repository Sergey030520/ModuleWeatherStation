//
// Created by sergey-athlete on 03.04.23.
//

#ifndef MODULEWEATHERSTATION_WEATHERSTATIONWIN_H
#define MODULEWEATHERSTATION_WEATHERSTATIONWIN_H

#include <QMainWindow>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <array>
#include <thread>
#include <atomic>
#include "../../include/Sensor/ISensor.h"


using namespace std;

enum  DescriptionSections{
    FORECAST, EXTERNAL_SENSOR, TIME_WITH_DATE, BAROMETER, GRAPH
};

class WeatherStationWin : public QMainWindow{
protected:
    Q_OBJECT
protected:
    QWidget *centralWidget;
    QGridLayout *centralLayout;

    array<QGridLayout *, 5> sectionLayouts;
    array<QLabel*, 5> labelSections;
    array<QLabel*, 3> labelSensors;
    array<QLabel*, 3> sensorsValue;

    QLabel *time, *date;
    QLabel *imgWeather;
    QLabel *weatherLabel;

    std::atomic<bool> isEndUpdateDateTime;
    std::thread* thrUpdateDateTime;

    QFont digitalFont;
    QFont charsFont;
private:
    void updateTimeDate();
public:
    explicit WeatherStationWin(QWidget *parent);
    virtual ~WeatherStationWin();
};


#endif //MODULEWEATHERSTATION_WEATHERSTATIONWIN_H
