#include "component.hpp"
#include <stdexcept>
#include <string>

Component::Component(Vector2 pos, Vector2 size):position(pos), size(size){

}

Component::~Component(){

}

Vector2 Component::getPos() const{
    return position;
}

void Component::setPos(Vector2 pos){
    if(pos.x < 0 || pos.y < 0){
        throw std::invalid_argument("invalid component position : ["
            +std::to_string(pos.x)+", "
            +std::to_string(pos.y)+"]");
    }
    position = pos;
}

Vector2 Component::getSize() const{
    return size;
}

void Component::setSize(Vector2 size){
    if(size.x < 0 || size.y < 0){
        throw std::invalid_argument("invalid component size : ["
            +std::to_string(size.x)+", "
            +std::to_string(size.y)+"]");
    }
    this->size = size;
}

void Component::fit(){

}

void Component::layout(){

}

bool Component::isShown() const{
    return shown;
}

void Component::show(bool isShown){
    shown = isShown;
}

void Component::draw() const{
    if(!isShown()){
        return;
    }
    DrawRectangleV(getPos(), getSize(), VIOLET);
}

bool Component::isMouseInside(){
    return CheckCollisionPointRec(GetMousePosition(), Rectangle{getPos().x, getPos().y, getSize().x, getSize().y});
}

void Component::toStr(std::ostream& stream) const{
    stream<<getPos()<<", "<<getSize();
}

std::ostream& operator<<(std::ostream& stream, const Vector2& vec){
    stream<<"["<<vec.x<<", "<<vec.y<<"]";
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Component& component){
    component.toStr(stream);
    return stream;
}
