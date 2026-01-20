#include "label.hpp"

Label::Label(TextModel& textModel):textModel(textModel){

}

TextModel& Label::getTextModel() const{
    return textModel;
}

void Label::setTextModel(TextModel& model){
    textModel = model;
}

void Label::draw() const{
    if(!isShown()){
        return;
    }
    Vector2 pos = getPos();
    pos.x += center.x;
    pos.y += center.y;
    textModel.draw(pos);
}

void Label::layout(){
    const Vector2 textSize = textModel.getSize();

    center.x = (getSize().x - textSize.x)/2;
    center.y = (getSize().y - textSize.y)/2;
}

void Label::fit(){
    const Vector2 textSize = textModel.getSize();
    setSize(textSize);
}

void Label::toStr(std::ostream& stream) const{
    stream<<"Label : ";
    Component::toStr(stream);
}