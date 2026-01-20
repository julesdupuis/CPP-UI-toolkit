#pragma once

#include "box.hpp"
#include "../model/buttonModel.hpp"
#include "../event/inputListener.hpp"

class Button : public Box{

private:
    ButtonModel& buttonModel;

    enum class State{
        IDLE,
        HOVERED,
        PRESSED,
        PRESSED_OUT,
    };
    State state = State::IDLE;

    InputListener hoverListener;
    InputListener pressListener;

public:
    Button(ButtonModel& buttonModel);

    ButtonModel& getButtonModel() const;
    void setButtonModel(ButtonModel& buttonModel);

    virtual void draw() const override;

    virtual void toStr(std::ostream& stream) const override;

};