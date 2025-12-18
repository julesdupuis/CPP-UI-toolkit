#pragma once

#include "Action.hpp"
#include "drawable.hpp"
#include "../event/inputListener.hpp"
#include <raylib.h>
#include <string>

class Button : public Drawable{

private:
    std::string text;
    Action action;

    bool isHovered = false;
    InputListener hoverListener;
    bool isPressed = false;
    InputListener pressListener;

    bool isMouseInside();

public:
    Button();

    void setText(const std::string& text);
    void setAction(Action& action);

    virtual void draw() const override;

};