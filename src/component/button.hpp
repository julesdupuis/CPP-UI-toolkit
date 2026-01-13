#pragma once

#include "action.hpp"
#include "component.hpp"
#include "../event/inputListener.hpp"
#include <string>

class Button : public Component{

private:
    std::string text;
    Action& action;

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
    Button(Action& action);

    void setText(const std::string& text);
    Action& getAction() const;
    void setAction(Action& action);

    virtual void layout() override;

    virtual void fit() override;
    virtual void draw() const override;

};