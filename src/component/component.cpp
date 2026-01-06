#include "component.hpp"

Component::Component(Vector2 pos, Vector2 size):position(pos), size(size){

}

Vector2 Component::getPos() const{
    return position;
}

void Component::setPos(Vector2 pos){
    position = pos;
}

Vector2 Component::getSize() const{
    return size;
}

void Component::setSize(Vector2 size){
    this->size = size;
}

void Component::fit(){

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
    DrawRectangleV(getPos(), getSize(), SKYBLUE);
}