#include "label.hpp"

Label::Label(TextElement&& text):text(text){

}

TextElement& Label::getText() const{
    return const_cast<TextElement&>(text);
}

void Label::draw() const{
    text.draw(getPos());
}