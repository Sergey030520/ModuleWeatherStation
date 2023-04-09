//
// Created by sergey-athlete on 28.03.23.
//

#include "../../../include/Sensor/Window/DoubleSlider.h"

DoubleSlider::DoubleSlider(QWidget *parent) : QSlider(parent) {

    connect(this, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
    setSingleStep(1);
    setOrientation(Qt::Horizontal);
    setFocusPolicy(Qt::NoFocus);

}

void DoubleSlider::setRange(double min, double max) {
    QSlider::setRange((int)(min*multiplier), (int)(max * multiplier));
    emit rangeChanged(minimum(), maximum());
}

void DoubleSlider::setMinimum(double min) {
    QSlider::setMinimum((int)(min*multiplier));
}

double DoubleSlider::minimum() const {
    return QAbstractSlider::maximum()/multiplier;
}

void DoubleSlider::setMaximum(double max) {
    QSlider::setMaximum((int)(max*multiplier));
}

double DoubleSlider::maximum() const {
    return QAbstractSlider::maximum()/multiplier;
}

double DoubleSlider::singleStep() const {
    return QAbstractSlider::singleStep()/multiplier;
}

void DoubleSlider::setSingleStep(double step) {
    QSlider::setSingleStep((int)(step * multiplier));
}

void DoubleSlider::setPageStep(double step) {
    QSlider::setPageStep((int)(step * multiplier));
}

void DoubleSlider::setSliderPosition(double newPos) {
    QSlider::setSliderPosition((int)(newPos * multiplier));
}

double DoubleSlider::sliderPosition() const {
    return QAbstractSlider::sliderPosition();
}

double DoubleSlider::pageStep() const {
    return QAbstractSlider::pageStep();
}

void DoubleSlider::setValue(int value) {
    emit valueChanged((double)value/multiplier);
}

void DoubleSlider::setValue(double value, bool blockSignals) {
    QSlider::blockSignals(blockSignals);
    QSlider::setValue((int)(value*multiplier));
    if(!blockSignals){
        emit valueChanged(value);
    }
    QSlider::blockSignals(false);
}
