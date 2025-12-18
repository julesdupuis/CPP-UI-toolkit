#include "button.hpp"

Button::Button():
hoverListener([this]{return isMouseInside();},
[this]{
    isHovered = true;
}),
pressListener([this]{return isMouseInside() && IsMouseButtonDown(MouseButton::MOUSE_BUTTON_LEFT);},
[this]{
    isPressed = true;
}){

}

bool Button::isMouseInside(){
    return CheckCollisionPointRec(GetMousePosition(), Rectangle{getPos().x, getPos().y, getSize().x, getSize().y});
}

void Button::setText(const std::string& text){
    this->text = text;
}

void Button::setAction(Action& action){
    this->action = action;
}

void Button::draw() const{
    Color buttonColor = SKYBLUE;
    if(isHovered){
        buttonColor = LIME;
    }
    if(isPressed){
        buttonColor = RED;
    }
    DrawRectangleV(getPos(), getSize(), buttonColor);

    int fontSize = 10;
    int textHorizontalSize = MeasureText(text.c_str(), fontSize);
    int textBeginX = getPos().x + (getSize().x - textHorizontalSize)/2;
    int textBeginY = getPos().y + (getSize().y - fontSize)/2;
    DrawText(text.c_str(), textBeginX, textBeginY, fontSize, BLACK);
}