#include "label.hpp"

#ifdef DEBUG_LAYOUT_SIZES
#include <iostream>
#endif

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

void Label::layout(){
#ifdef DEBUG_LAYOUT_SIZES
    const Vector2 pos = getPos();
    const Vector2 size = getSize();
    std::cerr<<"Label{"<<pos.x<<", "<<pos.y<<"}, {"
    <<size.x<<", "<<size.y<<"}\n";
#endif
}