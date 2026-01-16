#include "label.hpp"

Label::Label(TextModel& textModel):textModel(textModel){

}

TextModel& Label::getTextModel() const{
    return const_cast<TextModel&>(textModel);
}

void Label::setTextModel(TextModel& model){
    textModel = model;
}

void Label::draw() const{
    if(!isShown()){
        return;
    }
    Vector2 pos = getPos();
    const Vector2 textSize = getTextModel().getSize();
    pos.x += (getSize().x - textSize.x)/2;
    pos.y += (getSize().y - textSize.y)/2;
    textModel.draw(pos);
}

void Label::fit(){
    Vector2 size = textModel.getSize();
    size.x += 20;
    size.y += 20;
    setSize(size);
}

void Label::toStr(std::ostream& stream) const{
    stream<<"Label : ";
    Component::toStr(stream);
}