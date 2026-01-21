#include "gauge.hpp"

Gauge::Gauge(BoundedRangeModel& boundedRangeModel):
rangeModel(boundedRangeModel){

}

BoundedRangeModel& Gauge::getBoundedRangeModel() const{
    return rangeModel;
}

void Gauge::setBoundedRangeModel(BoundedRangeModel& model){
    rangeModel = model;
}

void Gauge::SetBarColor(Color color){
    barColor = color;
}

void Gauge::draw() const{
    Vector2 size = getSize();
    if(isVertical()){
        size.y *= rangeModel.getRatio();
    }else{
        size.x *= rangeModel.getRatio();
    }
    DrawRectangleV(getPos(), size, YELLOW);
}

void Gauge::fit(){
    // pixels per units of range
    const int unitSize = 2;
    Vector2 size = {10, 10};
    if(isVertical()){
        size.y = (rangeModel.getMaxValue() - rangeModel.getMinValue()) * unitSize;
    }else{
        size.x = (rangeModel.getMaxValue() - rangeModel.getMinValue()) * unitSize;
    }
}

void Gauge::toStr(std::ostream& stream) const{
    stream<<"Gauge : ";
    OrientedComponent::toStr(stream);
}