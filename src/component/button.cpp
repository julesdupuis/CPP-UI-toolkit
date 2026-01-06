#include "button.hpp"
#include <raylib.h>

Button::Button():
hoverListener([this]{return isMouseInside();},
[this]{
    switch(state){
    case State::IDLE:
        state = State::HOVERED;
        break;
    case State::PRESSED_OUT:
        state = State::PRESSED;
        break;
    default:
        break;
    }
},
[this]{
    switch(state){
    case State::HOVERED:
        state = State::IDLE;
        break;
    case State::PRESSED:
        state = State::PRESSED_OUT;
        break;
    default:
        break;
    }
}),
pressListener([]{return IsMouseButtonDown(MouseButton::MOUSE_BUTTON_LEFT);},
[this]{
    switch(state){
    case State::HOVERED:
        state = State::PRESSED;
        break;
    default:
        break;
    }
},
[this]{
    switch(state){
    case State::PRESSED:
        Event e;
        action.fireEvent(e);
        state = State::HOVERED;
        break;
    case State::PRESSED_OUT:
        state = State::IDLE;
        break;
    default:
        break;
    }
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

void Button::fit(){
    int fontSize = 10;
    // TODO fix wrong ordering : GetFontDefault is only available after InitWindow
    Vector2 size = MeasureTextEx(GetFontDefault(), text.c_str(), fontSize, 1);
    size.x += 10*2;
    size.y += 10*2;
    setSize(size);
}

void Button::draw() const{
    Color buttonColor;
    switch(state){
    case State::IDLE:
        buttonColor = SKYBLUE;
        break;
    case State::HOVERED:
        buttonColor = LIME;
        break;
    case State::PRESSED:
        buttonColor = RED;
        break;
    case State::PRESSED_OUT:
        buttonColor = ORANGE;
        break;
    default:
        buttonColor = BLANK;
        break;
    }
    DrawRectangleV(getPos(), getSize(), buttonColor);

    int fontSize = 10;
    int textHorizontalSize = MeasureText(text.c_str(), fontSize);
    int textBeginX = getPos().x + (getSize().x - textHorizontalSize)/2;
    int textBeginY = getPos().y + (getSize().y - fontSize)/2;
    DrawText(text.c_str(), textBeginX, textBeginY, fontSize, BLACK);
}