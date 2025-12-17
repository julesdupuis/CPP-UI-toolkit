#include "button.hpp"
#include <raylib.h>
#include <string>

Button::Button(const std::string& text):text(text){

}

void Button::draw() const{
    Drawable::draw();
    int fontSize = 10;
    int textHorizontalSize = MeasureText(text.c_str(), fontSize);
    int textBeginX = getPos().x + (getSize().x - textHorizontalSize)/2;
    int textBeginY = getPos().y + (getSize().y - fontSize)/2;
    DrawText(text.c_str(), textBeginX, textBeginY, fontSize, BLACK);
}