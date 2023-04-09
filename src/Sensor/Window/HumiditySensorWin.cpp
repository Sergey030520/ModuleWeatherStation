//
// Created by sergey-athlete on 02.04.23.
//

#include "../../../include/Sensor/Window/HumiditySensorWin.h"

using namespace std;


HumiditySensorWin::HumiditySensorWin(HumiditySensor &anotherSensor, QWidget *parent) :
        HumiditySensor(anotherSensor), SensorWindow(300, 300, parent) {
    initGui();
}
HumiditySensorWin::HumiditySensorWin(float inSensorError, QWidget *parent) :
    HumiditySensor(inSensorError), SensorWindow(300, 300, parent) {
    initGui();
}

HumiditySensorWin::HumiditySensorWin(string newName, float inSensorError, QWidget *parent) :
        HumiditySensor(std::move(newName), inSensorError), SensorWindow(300, 300, parent) {
    initGui();
}


void HumiditySensorWin::initGui() {
    setWindowTitle(QString(this->getName().c_str()));

    slider->setValue(this->getValue());
    slider->setRange(this->getLimit().getMinValue(), this->getLimit().getMaxValue());

    currentValueSensor->setText(QString("Value: ").append(QString().number(this->getValue(), 'f',
                                                                           2)));

    valueSensorField->setRange(this->getLimit().getMinValue(), this->getLimit().getMaxValue());
    valueSensorField->setValue(this->getValue());

    connect(slider, &DoubleSlider::valueChanged, this, &HumiditySensorWin::updateSlider);
    connect(btnLoadNewValueSensor, SIGNAL(released()), this, SLOT(updateValueSensor()));

    repaint();
    show();
}

void HumiditySensorWin::updateSlider(double position) {
    this->setValue((float) position);
    currentValueSensor->setText(QString("Value: ").append(QString().number(position, 'f',2)));
}

void HumiditySensorWin::updateValueSensor() {
    this->setValue((float) valueSensorField->value());
    slider->setValue(valueSensorField->value());
}



