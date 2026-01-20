#include "button.hpp"

Button::Button(ButtonModel& buttonModel):
buttonModel(buttonModel),
hoverListener([this]{return isMouseInside();},
[this]{
    switch(state){
    case State::IDLE:
        this->buttonModel.fireHoverInEvent();
        SetMouseCursor(MouseCursor::MOUSE_CURSOR_POINTING_HAND);
        state = State::HOVERED;
        break;
    case State::PRESSED_OUT:
        this->buttonModel.firePressedEnteringEvent();
        state = State::PRESSED;
        break;
    default:
        break;
    }
},
[this]{
    switch(state){
    case State::HOVERED:
        this->buttonModel.fireHoverOutEvent();
        SetMouseCursor(MouseCursor::MOUSE_CURSOR_DEFAULT);
        state = State::IDLE;
        break;
    case State::PRESSED:
        this->buttonModel.firePressedLeavingEvent();
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
        this->buttonModel.firePressEvent();
        state = State::PRESSED;
        break;
    default:
        break;
    }
},
[this]{
    switch(state){
    case State::PRESSED:
        this->buttonModel.fireReleaseEvent();
        state = State::HOVERED;
        break;
    case State::PRESSED_OUT:
        this->buttonModel.fireReleaseOutsideEvent();
        SetMouseCursor(MouseCursor::MOUSE_CURSOR_DEFAULT);
        state = State::IDLE;
        break;
    default:
        break;
    }
}){
    const int borderSize = 4;
    setInsets({borderSize, borderSize, borderSize, borderSize});
}

ButtonModel& Button::getButtonModel() const{
    return buttonModel;
}

void Button::setButtonModel(ButtonModel& buttonModel){
    this->buttonModel = buttonModel;
}

void Button::draw() const{
    if(!isShown()){
        return;
    }
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

    Box::draw();
}

void Button::toStr(std::ostream& stream) const{
    stream<<"Button : ";
    Box::toStr(stream);
}