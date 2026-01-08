#include "label.hpp"

Label::Label(TextModel&& textModel):textModel(textModel){

}

TextModel& Label::getText() const{
    return const_cast<TextModel&>(textModel);
}

void Label::draw() const{
    textModel.draw(getPos());
}