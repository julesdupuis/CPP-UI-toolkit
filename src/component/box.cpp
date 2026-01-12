#include "box.hpp"

Color Box::getBackgroundColor() const{
    return backgroundColor;
}

void Box::SetBackgroundColor(Color color){
    backgroundColor = color;
}

Vector4 Box::getInsets() const{
    return insets;
}

void Box::setInsets(Vector4 insets){
    this->insets = insets;
}

void Box::add(Component& component){
    this->component = &component;
}

void Box::remove(){
    this->component = nullptr;
}

void Box::draw() const{
    if(!isShown()){
        return;
    }
    DrawRectangleV(getPos(), getSize(), backgroundColor);
    if(component != nullptr){
        component->draw();
    }
}

void Box::layout(){
    if(component != nullptr){
        Vector2 pos = getPos();
        pos.x += insets.x;
        pos.y += insets.y;
        component->setPos(pos);

        Vector2 size = getSize();
        size.x -= insets.x + insets.z;
        size.y -= insets.y + insets.w;
        component->setSize(size);
    }
}

void Box::fit(){
    if(component != nullptr){
        Vector2 componentSize = getSize();
        componentSize.x += insets.x + insets.z;
        componentSize.y += insets.y + insets.w;
        setSize(componentSize);
    }
}