#include "slider.hpp"

Slider::Slider(BoundedRangeModel& boundedRangeModel):
rangeModel(boundedRangeModel),
buttonMinus(actionMinus),
buttonPlus(actionPlus),
buttonKnob(actionKnob),
minusListener([this](){
    this->rangeModel.setCurrentValue(this->rangeModel.getCurrentValue()-10); // TODO change increment value
}),
plusListener([this](){
    this->rangeModel.setCurrentValue(this->rangeModel.getCurrentValue()+10); // TODO change increment value
}),
knobListener([this](){
    Vector2 pos = buttonKnob.getPos();
    if(isVertical()){
        pos.y = barPos.y + (barSize.y - buttonThickness) * rangeModel.getRatio();
    }else{
        pos.x = barPos.x + (barSize.x - buttonThickness) * rangeModel.getRatio();
    }
    buttonKnob.setPos(pos);
}){
    actionMinus.subscribe(minusListener);
    actionPlus.subscribe(plusListener);
    // actionKnob.subscribe(knobListener);
    rangeModel.subscribe(knobListener);

    buttonMinus.setText("-");
    buttonPlus.setText("+");
    buttonKnob.setText("*");
}

Slider::~Slider(){
    actionMinus.unsubscribe(minusListener);
    actionPlus.unsubscribe(plusListener);
    // actionKnob.unsubscribe(knobListener);
    rangeModel.unsubscribe(knobListener);
}

BoundedRangeModel& Slider::getBoundedRangeModel() const{
    return rangeModel;
}

void Slider::setBoundedRangeModel(BoundedRangeModel& model){
    rangeModel = model;
}

bool Slider::isVertical() const{
    return vertical;
}

void Slider::setVertical(bool isVertical){
    vertical = isVertical;
}

void Slider::setBarThickness(int value){
    barThickness = value;
}

void Slider::setButtonThickness(int value){
    buttonThickness = value;
}

void Slider::draw() const{
    if(!isShown()){
        return;
    }
    DrawRectangleV(barPos, barSize, WHITE);

    buttonKnob.draw();

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

    barPos = pos;
    barSize = size;
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

    Vector2 knobPos = barPos;
    Vector2 knobSize = size;
    if(isVertical()){
        knobSize.y = buttonThickness;
        knobPos.x += (barSize.x - knobSize.x)/2;
        knobPos.y += (barSize.y - buttonThickness) * rangeModel.getRatio();
    }else{
        knobSize.x = buttonThickness;
        knobPos.y += (barSize.y - knobSize.y)/2;
        knobPos.x += (barSize.x - buttonThickness) * rangeModel.getRatio();
    }
    buttonKnob.setPos(knobPos);
    buttonKnob.setSize(knobSize);
}

void Slider::fit(){

}