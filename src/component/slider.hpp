#pragma once

#include "button.hpp"
#include "component.hpp"
#include "../model/boundedRangeModel.hpp"
#include "../model/textModel.hpp"
#include "label.hpp"

class Slider : public Component{

private:
    BoundedRangeModel& rangeModel;
    bool vertical = false;

    int barThickness = 5;
    int buttonThickness = 20;

    Vector2 barPos;
    Vector2 barSize;

    TextModel minusText;
    TextModel plusText;
    TextModel knobText;

    Label minusLabel;
    Label plusLabel;
    Label knobLabel;

    Button buttonMinus;
    Button buttonPlus;
    Button buttonKnob;

    ButtonModel modelMinus;
    ButtonModel modelPlus;
    ButtonModel modelKnob;
    Listener minusListener;
    Listener plusListener;
    Listener knobListener;
    FrameListener knobMovementListener;
    Listener knobGrabListener;
    Listener knobUngrabListener;

    Vector2 mousePosOnKnob = {0, 0};

public:
    Slider(BoundedRangeModel& boundedRangeModel);
    ~Slider();

    BoundedRangeModel& getBoundedRangeModel() const;
    void setBoundedRangeModel(BoundedRangeModel& model);

    bool isVertical() const;
    void setVertical(bool isVertical);

    int getBarThickness() const;
    int getButtonThickness() const;
    void setBarThickness(int value);
    void setButtonThickness(int value);

    virtual void draw() const override;
    virtual void layout() override;
    virtual void fit() override;

    virtual void toStr(std::ostream& stream) const override;

};