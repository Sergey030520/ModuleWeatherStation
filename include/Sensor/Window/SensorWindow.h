//
// Created by sergey-athlete on 27.03.23.
//

#ifndef MODULEWEATHERSTATION_SENSORWINDOW_H
#define MODULEWEATHERSTATION_SENSORWINDOW_H

#include <QMainWindow>
#include "DoubleSlider.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QCheckBox>


class SensorWindow : public QMainWindow{
protected:
Q_OBJECT
protected:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;

    DoubleSlider *slider;
    QLabel *currentValueSensor;

    QHBoxLayout *layoutSettingValueSensor;
    QDoubleSpinBox *valueSensorField;

    QPushButton *btnLoadNewValueSensor;

    virtual void initGui() = 0;

public:
    SensorWindow(int height = 300, int width = 300, QWidget* parent = nullptr);
    virtual ~SensorWindow() {};
private slots:
    virtual void updateSlider(double position) = 0;
    virtual void updateValueSensor() = 0;
    void updateValueSensor(double newValue);
};


#endif //MODULEWEATHERSTATION_SENSORWINDOW_H
