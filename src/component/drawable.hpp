#pragma once

#include "component.hpp"
#include <raylib.h>

class Drawable : public Component{

private:
    bool shown = true;

public:
    virtual void draw() const;
    void show(bool isShown);
};