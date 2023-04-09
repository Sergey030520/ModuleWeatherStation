//
// Created by sergey-athlete on 02.04.23.
//

#include "../../../include/Sensor/Window/BarometerSensorWin.h"


using namespace std;

BarometerSensorWin::BarometerSensorWin(BarometerSensor &sensor, QWidget *parent):
        BarometerSensor(sensor), SensorWindow(300, 300, parent) {
    initGui();
}

BarometerSensorWin::BarometerSensorWin(SensorLimitations &inLimit, float inSensorError, QWidget *parent)
    : BarometerSensor(inLimit, inSensorError), SensorWindow(300, 300, parent){
    initGui();
}

BarometerSensorWin::BarometerSensorWin(string inName,
                                       SensorLimitations &inLimit, float inSensorError,QWidget *parent) :
                                       BarometerSensor(std::move(inName), inLimit, inSensorError),
                                       SensorWindow(300, 300, parent){
    initGui();
}

void BarometerSensorWin::initGui() {
    setWindowTitle(QString(this->getName().c_str()));

    slider->setValue(this->getValue());
    slider->setRange(this->getLimit().getMinValue(), this->getLimit().getMaxValue());

    currentValueSensor->setText(QString("Value: ").append(QString().number(this->getValue(), 'f',
    2)));
    valueSensorField->setRange(this->getLimit().getMinValue(), this->getLimit().getMaxValue());
    valueSensorField->setValue(this->getValue());

    connect(slider, &DoubleSlider::valueChanged, this, &BarometerSensorWin::updateSlider);
    connect(btnLoadNewValueSensor, SIGNAL(released()), this, SLOT(updateValueSensor()));

    repaint();
    show();
}

void BarometerSensorWin::updateSlider(double position) {
    this->setValue((float) position);
    currentValueSensor->setText(QString("Value: ").append(QString().number(position, 'f',2)));
}

void BarometerSensorWin::updateValueSensor() {
    this->setValue((float) valueSensorField->value());
    slider->setValue(valueSensorField->value());
}
