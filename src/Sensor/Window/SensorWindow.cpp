//
// Created by sergey-athlete on 27.03.23.
//

#include "../../../include/Sensor/Window/SensorWindow.h"
#include <string>

SensorWindow::SensorWindow(int height, int width, QWidget *parent){
    setParent(parent);
    setFixedSize(width, height);

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    verticalLayout = new QVBoxLayout(centralWidget);
    layoutSettingValueSensor = new QHBoxLayout();

    currentValueSensor = new QLabel("");

    currentValueSensor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    currentValueSensor->setAlignment(Qt::AlignCenter);
    currentValueSensor->setStyleSheet(QString("border: 2px solid #FFF; font-size: 25px; background-color: #0F0"));


    slider = new DoubleSlider(centralWidget);
    slider->setOrientation(Qt::Orientation::Horizontal);
    slider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    slider->setSingleStep(0.1);

    valueSensorField = new QDoubleSpinBox(centralWidget);
    valueSensorField->setSingleStep(0.1);

    btnLoadNewValueSensor = new QPushButton("load new value sensor", centralWidget);

    layoutSettingValueSensor->addWidget(valueSensorField);
    layoutSettingValueSensor->addWidget(btnLoadNewValueSensor);

    verticalLayout->insertWidget(0, currentValueSensor);
    verticalLayout->insertWidget(1, slider);
    verticalLayout->insertLayout(2, layoutSettingValueSensor);

    centralWidget->setLayout(verticalLayout);

    connect(slider, SIGNAL(valueChanged(double)), this, SLOT(updateValueSensor(double)));
    connect(slider, &DoubleSlider::valueChanged, this, &SensorWindow::updateSlider);
    connect(btnLoadNewValueSensor, SIGNAL(released()), this, SLOT(updateValueSensor()));
}


void SensorWindow::updateValueSensor(double newValue) {
    valueSensorField->setValue(newValue);
}

