#include "drawable.hpp"
#include <raylib.h>

void Drawable::show(bool isShown){
    shown = isShown;
}

void Drawable::draw() const{
    DrawRectangleV(getPos(), getSize(), SKYBLUE);
}