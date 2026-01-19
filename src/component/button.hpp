#pragma once

#include "../model/buttonModel.hpp"
#include "component.hpp"
#include "../event/inputListener.hpp"
#include <string>

class Button : public Component{

private:
    std::string text;
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

    void setText(const std::string& text);

    ButtonModel& getButtonModel() const;
    void setButtonModel(ButtonModel& buttonModel);

    virtual void fit() override;
    virtual void draw() const override;

    virtual void toStr(std::ostream& stream) const override;

};