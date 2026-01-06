#pragma once

#include "action.hpp"
#include "component.hpp"
#include "../event/inputListener.hpp"
#include <raylib.h>
#include <string>

class Button : public Component{

private:
    std::string text;
    Action action;

    enum class State{
        IDLE,
        HOVERED,
        PRESSED,
        PRESSED_OUT,
    };
    State state = State::IDLE;
    InputListener hoverListener;
    InputListener pressListener;

    bool isMouseInside();

public:
    Button();

    void setText(const std::string& text);
    void setAction(Action& action);

    virtual void fit() override;
    virtual void draw() const override;

};