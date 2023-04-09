#include <QApplication>
#include <QPushButton>
#include "../include/Sensor/Window/SensorWindow.h"
#include "../include/Sensor/Window/TemperatureSensorWin.h"
#include "../include/Sensor/Window/BarometerSensorWin.h"
#include "../include/Sensor/Window/HumiditySensorWin.h"
#include "../include/WeatherStation/WeatherStation.h"
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SensorLimitations limitTemp(-100, 100);
    SensorLimitations limitBarometer(947, 1070);

    vector<ISensor*> sensors{new TemperatureSensorWin(limitTemp, 0.1),
                             new BarometerSensorWin(limitBarometer, 0.1),
                             new HumiditySensorWin(0.1)};

    WeatherStation weatherStation(sensors);
    weatherStation.show();

    return QApplication::exec();
}
