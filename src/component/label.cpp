#include "label.hpp"
#include <functional>

Label::Label(TextModel& textModel, TextRenderer& textRenderer):
textModel(textModel),
renderer(std::ref(textRenderer)){

}

TextModel& Label::getTextModel() const{
    return textModel;
}

void Label::setTextModel(TextModel& model){
    textModel = model;
}

LabelRenderer& Label::getLabelRenderer() const{
    return renderer;
}

void Label::setLabelRenderer(LabelRenderer& renderer){
    this->renderer = renderer;
}

void Label::draw() const{
    if(!isShown()){
        return;
    }
    renderer.drawText(getPos(), getTextModel());
}

void Label::layout(){

}

void Label::fit(){
    const Vector2 textSize = renderer.getSize(getTextModel());
    setSize(textSize);
}

void Label::toStr(std::ostream& stream) const{
    stream<<"Label : ";
    Component::toStr(stream);
}