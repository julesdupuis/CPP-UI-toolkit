#pragma once

#include "button.hpp"
#include "component.hpp"
#include "../model/boundedRangeModel.hpp"
#include "../event/inputListener.hpp"

class Slider : public Component{

private:
    BoundedRangeModel& rangeModel;
    bool vertical = false;

    int barThickness = 5;
    const int buttonThickness = 20;

    Button buttonMinus;
    Button buttonPlus;
    // Button buttonKnob;

    Action actionMinus;
    Action actionPlus;
    Listener minusListener;
    Listener plusListener;
    InputListener slideListener;

public:
    Slider(BoundedRangeModel& boundedRangeModel);
    ~Slider();

    BoundedRangeModel& getBoundedRangeModel() const;

    bool isVertical() const;
    void setVertical(bool isVertical);

    virtual void draw() const override;
    virtual void layout() override;
    virtual void fit() override;

};