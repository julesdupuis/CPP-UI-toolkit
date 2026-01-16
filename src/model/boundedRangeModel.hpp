#pragma once

#include "../event/observable.hpp"

class BoundedRangeModel : public Observable{

private:
    int minValue = 0;
    int maxValue = 100;
    int currentValue = 50;

public:
    int getMinValue() const;
    int getMaxValue() const;
    int getCurrentValue() const;

    float getRatio() const;

    void setMinValue(int value);
    void setMaxValue(int value);
    void setCurrentValue(int value);

    void setRatio(float value);

};