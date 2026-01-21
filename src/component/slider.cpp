#include "slider.hpp"

Slider::Slider(BoundedRangeModel& boundedRangeModel):
rangeModel(boundedRangeModel),
minusText("-"),
plusText("+"),
knobText("*"),
minusLabel(minusText),
plusLabel(plusText),
knobLabel(knobText),
buttonMinus(modelMinus),
buttonPlus(modelPlus),
buttonKnob(modelKnob),
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
    buttonKnob.layout();
}),
knobMovementListener([this](){
    if(isVertical()){
        rangeModel.setRatio(static_cast<float>(GetMouseY() - mousePosOnKnob.y - barPos.y)/static_cast<float>(barSize.y - buttonThickness));
    }else{
        rangeModel.setRatio(static_cast<float>(GetMouseX() - mousePosOnKnob.x - barPos.x)/static_cast<float>(barSize.x - buttonThickness));
    }
}),
knobGrabListener([this](){
    mousePosOnKnob = GetMousePosition();
    const Vector2 buttonPos = buttonKnob.getPos();
    mousePosOnKnob.x -= buttonPos.x;
    mousePosOnKnob.y -= buttonPos.y;
    knobMovementListener.enable(true);
}),
knobUngrabListener([this](){
    knobMovementListener.enable(false);
}){
    modelMinus.subscribeRelease(minusListener);
    modelPlus.subscribeRelease(plusListener);
    rangeModel.subscribe(knobListener);

    modelKnob.subscribePress(knobGrabListener);
    modelKnob.subscribeRelease(knobUngrabListener);
    modelKnob.subscribeReleaseOutside(knobUngrabListener);

    knobMovementListener.enable(false);

    buttonMinus.add(minusLabel);
    buttonPlus.add(plusLabel);
    buttonKnob.add(knobLabel);
}

Slider::~Slider(){
    modelMinus.unsubscribeRelease(minusListener);
    modelPlus.unsubscribeRelease(plusListener);
    rangeModel.unsubscribe(knobListener);

    modelKnob.unsubscribePress(knobGrabListener);
    modelKnob.unsubscribeRelease(knobUngrabListener);
    modelKnob.unsubscribeReleaseOutside(knobUngrabListener);
}

BoundedRangeModel& Slider::getBoundedRangeModel() const{
    return rangeModel;
}

void Slider::setBoundedRangeModel(BoundedRangeModel& model){
    rangeModel = model;
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
    // pos stays 0 relative to component
    buttonMinus.setPos(buttonMinusPos);
    buttonMinus.layout();

    Vector2 buttonPlusPos = pos;
    const Vector2 buttonPlusSize = buttonPlus.getSize();
    if(isVertical()){
        buttonPlusPos.y += size.y - buttonPlusSize.y;
    }else{
        buttonPlusPos.x += size.x - buttonPlusSize.x;
    }
    buttonPlus.setPos(buttonPlusPos);
    buttonPlus.layout();

    barPos = pos;
    if(isVertical()){
        barPos.x += (size.x - barThickness)/2;
        barPos.y += buttonThickness;
        barSize.y = size.y - 2*buttonThickness;
    }else{
        barPos.y += (size.y - barThickness)/2;
        barPos.x += buttonThickness;
        barSize.x = size.x - 2*buttonThickness;
    }

    Vector2 knobPos = barPos;
    const Vector2 knobSize = size;
    if(isVertical()){
        knobPos.x += (barSize.x - knobSize.x)/2;
        knobPos.y += (barSize.y - buttonThickness) * rangeModel.getRatio();
        if(knobPos.y < 0){
            knobPos.y = 0;
        }
    }else{
        knobPos.y += (barSize.y - knobSize.y)/2;
        knobPos.x += (barSize.x - buttonThickness) * rangeModel.getRatio();
        if(knobPos.x < 0){
            knobPos.x = 0;
        }
    }
    buttonKnob.setPos(knobPos);
    buttonKnob.layout();
}

void Slider::fit(){
    buttonMinus.fit();
    Vector2 buttonMinusSize = buttonMinus.getSize();
    if(isVertical()){
        buttonMinusSize.y = buttonThickness;
    }else{
        buttonMinusSize.x = buttonThickness;
    }
    buttonMinus.setSize(buttonMinusSize);

    buttonPlus.fit();
    Vector2 buttonPlusSize = buttonPlus.getSize();
    if(isVertical()){
        buttonPlusSize.y = buttonThickness;
    }else{
        buttonPlusSize.x = buttonThickness;
    }
    buttonPlus.setSize(buttonPlusSize);

    // pixels per units of range
    const int unitSize = 2;
    barSize = {0, 0};
    if(isVertical()){
        barSize.x = barThickness;
        barSize.y = (rangeModel.getMaxValue() - rangeModel.getMinValue()) * unitSize;
    }else{
        barSize.y = barThickness;
        barSize.x = (rangeModel.getMaxValue() - rangeModel.getMinValue()) * unitSize;
    }

    buttonKnob.fit();
    Vector2 knobSize = buttonKnob.getSize();
    if(isVertical()){
        knobSize.y = buttonThickness;
    }else{
        knobSize.x = buttonThickness;
    }
    buttonKnob.setSize(knobSize);

    Vector2 size = {0, 0};
    if(isVertical()){
        size.x = std::max({buttonMinusSize.x, buttonPlusSize.x, knobSize.x, barSize.x});
        size.y = buttonMinusSize.y + buttonPlusSize.y + barSize.y;
    }else{
        size.y = std::max({buttonMinusSize.y, buttonPlusSize.y, knobSize.y, barSize.y});
        size.x = buttonMinusSize.x + buttonPlusSize.x + barSize.x;
    }
    setSize(size);
}

void Slider::toStr(std::ostream& stream) const{
    stream<<"Slider : ";
    OrientedComponent::toStr(stream);
}