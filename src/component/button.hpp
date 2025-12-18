#pragma once

#include "Action.hpp"
#include "drawable.hpp"
#include <raylib.h>
#include <string>

class Button : public Drawable{

private:
    std::string text;
    Action action;

    bool isHovered;
    bool isPressed;

public:
    Button(const std::string& text);

    virtual void draw() const override;

};