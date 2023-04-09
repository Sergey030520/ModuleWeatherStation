//
// Created by sergey-athlete on 02.04.23.
//

#include "../../../include/Sensor/Window/TemperatureSensorWin.h"

#include <iostream>
#include <QThread>

using namespace std;


TemperatureSensorWin::TemperatureSensorWin(TemperatureSensor &anotherSensor, QWidget *parent):
        TemperatureSensor(anotherSensor),SensorWindow(300, 300, parent){
    initGui();
}

TemperatureSensorWin::TemperatureSensorWin(SensorLimitations &newLimit, float inSensorError, QWidget *parent)
        : TemperatureSensor(newLimit, inSensorError), SensorWindow(300, 300, parent){
    initGui();
}

TemperatureSensorWin::TemperatureSensorWin(string newName, SensorLimitations &newLimit, float inSensorError,
                                           QWidget *parent)
        : TemperatureSensor(std::move(newName), newLimit, inSensorError),
        SensorWindow(300, 300, parent){
    initGui();
}

void TemperatureSensorWin::initGui() {
    setWindowTitle(QString(this->getName().c_str()));

    slider->setValue(this->getValue());
    slider->setRange(this->getLimit().getMinValue(), this->getLimit().getMaxValue());

    currentValueSensor->setText(QString("Value: ").append(QString().number(this->getValue(), 'f',
                                                                           2)));

    valueSensorField->setRange(this->getLimit().getMinValue(), this->getLimit().getMaxValue());
    valueSensorField->setValue(this->getValue());

    repaint();
    show();
}


void TemperatureSensorWin::updateSlider(double position) {
    this->setValue((float) position);
    currentValueSensor->setText(QString("Value: ").append(QString().number(position, 'f',2)));
}

void TemperatureSensorWin::updateValueSensor() {
    this->setValue((float) valueSensorField->value());
    slider->setValue(valueSensorField->value());
}





