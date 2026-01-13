#include "boundedRangeModel.hpp"

int BoundedRangeModel::getMinValue() const{
    return minValue;
}

int BoundedRangeModel::getMaxValue() const{
    return maxValue;
}

int BoundedRangeModel::getCurrentValue() const{
    return currentValue;
}

float BoundedRangeModel::getRatio() const{
    return static_cast<float>(getCurrentValue())/(static_cast<float>(getMaxValue() - getMinValue()));
}

void BoundedRangeModel::setMinValue(int value){
    minValue = value;
}

void BoundedRangeModel::setMaxValue(int value){
    maxValue = value;
}

void BoundedRangeModel::setCurrentValue(int value){
    if(value >= minValue && value <= maxValue){
        currentValue = value;
    }
}