#include "slider.hpp"
#include "button.hpp"

Slider::Slider(BoundedRangeModel& boundedRangeModel):
rangeModel(boundedRangeModel),
buttonMinus(actionMinus),
buttonPlus(actionPlus),
minusListener([this](){
    this->rangeModel.setCurrentValue(this->rangeModel.getCurrentValue()-10);
}),
plusListener([this](){
    this->rangeModel.setCurrentValue(this->rangeModel.getCurrentValue()+10);
}),
slideListener(
[](){
    return false;
},
[](){

}){
    actionMinus.subscribe(minusListener);
    actionPlus.subscribe(plusListener);
}

Slider::~Slider(){
    actionMinus.unsubscribe(minusListener);
    actionPlus.unsubscribe(plusListener);
}

BoundedRangeModel& Slider::getBoundedRangeModel() const{
    return rangeModel;
}

bool Slider::isVertical() const{
    return vertical;
}

void Slider::setVertical(bool isVertical){
    vertical = isVertical;
}

void Slider::draw() const{
    if(!isShown()){
        return;
    }
    const Vector2 pos = getPos();
    const Vector2 size = getSize();

    Vector2 barPos = pos;
    Vector2 barSize = size;
    if(isVertical()){
        barPos.x += (size.x - barThickness)/2;
        barSize.x = barThickness;
        barPos.y += buttonThickness;
        barSize.y -= 2*buttonThickness;
    }else{
        barPos.y += (size.y - barThickness)/2;
        barSize.y = barThickness;
        barPos.x += buttonThickness;
        barSize.x -= 2*buttonThickness;
    }
    DrawRectangleV(barPos, barSize, WHITE);

    Vector2 knobSize = size;
    Vector2 knobPos = barPos;
    if(isVertical()){
        knobSize.y = buttonThickness;
        knobPos.x += (barSize.x - knobSize.x)/2;
        knobPos.y += (barSize.y - buttonThickness) * rangeModel.getRatio();
    }else{
        knobSize.x = buttonThickness;
        knobPos.y += (barSize.y - knobSize.y)/2;
        knobPos.x += (barSize.x - buttonThickness) * rangeModel.getRatio();
    }
    DrawRectangleV(knobPos, knobSize, PURPLE);

    buttonMinus.draw();
    buttonPlus.draw();
}

void Slider::layout(){
    const Vector2 pos = getPos();
    const Vector2 size = getSize();

    Vector2 buttonMinusPos = pos;
    Vector2 buttonMinusSize = size;
    if(isVertical()){
        buttonMinusSize.y = buttonThickness;
        // pos stays 0 relative to component
    }else{
        buttonMinusSize.x = buttonThickness;
        // pos stays 0 relative to component
    }
    buttonMinus.setPos(buttonMinusPos);
    buttonMinus.setSize(buttonMinusSize);

    Vector2 buttonPlusPos = pos;
    Vector2 buttonPlusSize = size;
    if(isVertical()){
        buttonPlusSize.y = buttonThickness;
        buttonPlusPos.y += size.y - buttonPlusSize.y;
    }else{
        buttonPlusSize.x = buttonThickness;
        buttonPlusPos.x += size.x - buttonPlusSize.x;
    }
    buttonPlus.setPos(buttonPlusPos);
    buttonPlus.setSize(buttonPlusSize);
}

void Slider::fit(){

}