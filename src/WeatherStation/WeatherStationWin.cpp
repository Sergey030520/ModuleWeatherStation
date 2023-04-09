//
// Created by sergey-athlete on 03.04.23.
//

#include "../../include/WeatherStation/WeatherStationWin.h"
#include "../../include/WeatherStation/WeatherStation.h"
#include <QTime>
#include <QFontDatabase>

WeatherStationWin::WeatherStationWin(QWidget *parent) : isEndUpdateDateTime(false) {
    setMinimumSize(800, 600);
    setStyleSheet("background-color: #336");

    int idFontDigit = QFontDatabase::
    addApplicationFont("/../../../../../font/Digital/DIGITALDREAM.ttf");
    int idFontChars = QFontDatabase::
    addApplicationFont("/../../../../../font/Digital/DIGITALDREAMFATNARROW.ttf");

    QString family = QFontDatabase::applicationFontFamilies(idFontDigit).at(0);
    digitalFont = QFont(family);

    family = QFontDatabase::applicationFontFamilies(idFontChars).at(0);
    charsFont = QFont(family);

    centralWidget = new QWidget(this);
    centralLayout = new QGridLayout(centralWidget);
    centralWidget->setStyleSheet("border: 2px solid #000");

    for(auto & sectionLayout : sectionLayouts){
        sectionLayout = new QGridLayout();
        sectionLayout->setContentsMargins(0, 10, 10, 10);
    }
    for(auto &labelSensor : labelSensors){
        labelSensor = new QLabel();
        labelSensor->setStyleSheet("font-size: 28px;");
        labelSensor->setFont(digitalFont);
    }
    for(auto &value : sensorsValue){
        value = new QLabel();
        value->setStyleSheet("font-size: 25px;");
        value->setFont(charsFont);
    }

/*---------------------------------------------------------*/

    labelSections[FORECAST] = new QLabel("FORECAST");

    imgWeather = new QLabel();
    imgWeather->setPixmap(QPixmap("/../../../../../imgs/sun.png"));

    weatherLabel = new QLabel("");
    weatherLabel->setStyleSheet("font-size: 20px;");

    sectionLayouts[FORECAST]->addWidget(labelSections[FORECAST], 0, 0);
    sectionLayouts[FORECAST]->addWidget(imgWeather, 1, 0);
    sectionLayouts[FORECAST]->addWidget(weatherLabel, 2, 0);
/*-----------------------------------------------------------*/

    labelSections[TIME_WITH_DATE] = new QLabel("TIME");

    time = new QLabel(QTime::currentTime().toString("hh:mm:ss"));
    time->setStyleSheet("font-size: 40px;");
    time->setFixedHeight(45);
    time->setFont(digitalFont);


    date = new QLabel(QDate::currentDate().toString());
    date->setStyleSheet("font-size: 30px;");
    date->setFont(digitalFont);
    date->setFixedHeight(40);

    sectionLayouts[TIME_WITH_DATE]->addWidget(labelSections[TIME_WITH_DATE], 0, 0);
    sectionLayouts[TIME_WITH_DATE]->addWidget(time, 1, 0, 1, 2);
    sectionLayouts[TIME_WITH_DATE]->addWidget(date, 2, 0, 1, 2);

    /*-----------------------------------------------------------*/

    labelSections[EXTERNAL_SENSOR] = new QLabel("EXTERNAL SENSOR");

    labelSensors[TEMPERATURE_SENSOR]->setText("Temperature");
    sensorsValue[TEMPERATURE_SENSOR]->setText("21.9C");

    labelSensors[HUMIDITY_SENSOR]->setText("Humidity");
    sensorsValue[HUMIDITY_SENSOR]->setText("40%");

    sectionLayouts[EXTERNAL_SENSOR]->addWidget(labelSections[EXTERNAL_SENSOR], 0, 0, Qt::AlignTop);

    sectionLayouts[EXTERNAL_SENSOR]->addWidget(labelSensors[TEMPERATURE_SENSOR], 1, 0, Qt::AlignVCenter);
    sectionLayouts[EXTERNAL_SENSOR]->addWidget(sensorsValue[TEMPERATURE_SENSOR], 2, 0, Qt::AlignVCenter);

    sectionLayouts[EXTERNAL_SENSOR]->addWidget(labelSensors[HUMIDITY_SENSOR], 1, 1, Qt::AlignVCenter);
    sectionLayouts[EXTERNAL_SENSOR]->addWidget(sensorsValue[HUMIDITY_SENSOR], 2, 1, Qt::AlignVCenter);


    /*-----------------------------------------------------------*/

    labelSections[BAROMETER] = new QLabel("BAROMETER");
    sensorsValue[BAROMETRIC_PRESSURE_SENSOR]->setText("1028.5 BAR");
    sensorsValue[BAROMETRIC_PRESSURE_SENSOR]->setMaximumHeight(60);

    sectionLayouts[BAROMETER]->addWidget(labelSections[BAROMETER], 0, 0, Qt::AlignTop);
    sectionLayouts[BAROMETER]->addWidget(sensorsValue[BAROMETRIC_PRESSURE_SENSOR], 1, 0,1,
                                         2, Qt::AlignVCenter);
    /*-----------------------------------------------------------*/

    labelSections[GRAPH] = new QLabel("GRAPH");
    sectionLayouts[GRAPH]->addWidget(labelSections[GRAPH], 0, 0);

    /*-----------------------------------------------------------*/

    centralLayout->addLayout(sectionLayouts[TIME_WITH_DATE], 0, 0, Qt::AlignTop);
    centralLayout->addLayout(sectionLayouts[FORECAST], 0, 1, Qt::AlignTop);
    centralLayout->addLayout(sectionLayouts[EXTERNAL_SENSOR], 1, 0, Qt::AlignTop);
    centralLayout->addLayout(sectionLayouts[GRAPH], 1, 1, 2, 1, Qt::AlignTop);
    centralLayout->addLayout(sectionLayouts[BAROMETER], 2, 0, Qt::AlignTop);


    for(auto section : labelSections){
        section->setStyleSheet("background-color: #669; font-size: 30px; font-weight: bolder;");
        section->setFixedHeight(40);
        section->setFont(charsFont);
    }

    centralWidget->setLayout(centralLayout);
    setCentralWidget(centralWidget);

    thrUpdateDateTime = new std::thread(&WeatherStationWin::updateTimeDate, this);
}

void WeatherStationWin::updateTimeDate() {
    while (!isEndUpdateDateTime) {
        time->setText(QTime::currentTime().toString("hh:mm:ss"));
        date->setText(QDate::currentDate().toString());
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}

WeatherStationWin::~WeatherStationWin() {
    isEndUpdateDateTime = true;
    if(thrUpdateDateTime != nullptr) {
        thrUpdateDateTime->join();
        delete thrUpdateDateTime;
    }
}
