//
// Created by sergey-athlete on 28.03.23.
//

#ifndef MODULEWEATHERSTATION_DOUBLESLIDER_H
#define MODULEWEATHERSTATION_DOUBLESLIDER_H


#include <QSlider>

class DoubleSlider: public QSlider{
Q_OBJECT
private:
    double multiplier{10.0};
public:
    DoubleSlider(QWidget *parent = nullptr);

    void setRange(double min, double max);

    void setMinimum(double min);
    double minimum() const;

    void setMaximum(double max);
    double maximum() const;

    void setSliderPosition(double newPos);
    double sliderPosition() const;

    void setSingleStep(double step);
    double singleStep() const;

    void setPageStep(double step);
    double pageStep() const;

public slots:
    void setValue(int value);
    void setValue(double Value, bool BlockSignals = false);
signals:
    void valueChanged(double value);
    void rangeChanged(double min, double max);

};


#endif //MODULEWEATHERSTATION_DOUBLESLIDER_H
