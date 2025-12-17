#pragma once

#include "../event/observable.hpp"
#include "drawable.hpp"
#include <raylib.h>
#include <string>

class Button : public Drawable{

private:
    std::string text;
    Observable actionObservable;

public:
    Button(const std::string& text);

    virtual void draw() const override;

};