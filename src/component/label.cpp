#include "label.hpp"

Label::Label(TextModel& textModel):textModel(textModel){

}

TextModel& Label::getTextModel() const{
    return const_cast<TextModel&>(textModel);
}

void Label::draw() const{
    textModel.draw(getPos());
}

void Label::fit(){
    Vector2 size = textModel.getSize();
    size.x += 20;
    size.y += 20;
    setSize(size);
}