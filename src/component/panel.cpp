#include "panel.hpp"

Panel::Panel(LayoutManager& layoutManager):Container(layoutManager){

}

Color Panel::getBackgroundColor() const{
    return backgroundColor;
}

void Panel::setBackgroundColor(Color color){
    backgroundColor = color;
}

void Panel::draw() const{
    // draw background
    DrawRectangleV(getPos(), getSize(), getBackgroundColor());
    Container::draw();
}

void Panel::toStr(std::ostream& stream) const{
    stream<<"Panel : ";
    Container::toStr(stream);
}