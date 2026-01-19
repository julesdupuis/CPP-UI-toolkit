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
    return static_cast<float>(getCurrentValue() - getMinValue())/(static_cast<float>(getMaxValue() - getMinValue()));
}

void BoundedRangeModel::setMinValue(int value){
    minValue = value;
}

void BoundedRangeModel::setMaxValue(int value){
    maxValue = value;
}

void BoundedRangeModel::setCurrentValue(int value){
    if(value < minValue){
        currentValue = minValue;
        return;
    }
    if(value > maxValue){
        currentValue = maxValue;
        return;
    }
    currentValue = value;
    fireEvent();
}

void BoundedRangeModel::setRatio(float value){
    if(value < 0.0f){
        currentValue = minValue;
        return;
    }
    if(value > 1.0f){
        currentValue = maxValue;
        return;
    }
    currentValue = (getMaxValue() - getMinValue()) * value + getMinValue();
    fireEvent();
}

void BoundedRangeModel::toStr(std::ostream& stream) const{
    stream<<"["<<getMinValue()<<","<<getMaxValue()<<"]="
        <<getCurrentValue()<<"="<<getRatio();
}
