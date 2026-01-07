#include "textElement.hpp"
#include <string>

TextElement::TextElement(std::string text, Font font):
text(text), font(font){

}

Vector2 TextElement::getSize() const{
    return MeasureTextEx(font, text.c_str(), fontSize, spacing);
}

void TextElement::draw(Vector2 position) const{
    DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
}

std::string TextElement::getText() const{
    return text;
}

void TextElement::setText(std::string text){
    this->text = text;
}

Font TextElement::getFont() const{
    return font;
}

void TextElement::setFont(Font font){
    this->font = font;
}

float TextElement::getFontSize() const{
    return fontSize;
}

void TextElement::setFontSize(float size){
    fontSize = size;
}

float TextElement::getSpacing() const{
    return spacing;
}

void TextElement::setSpacing(float spacing){
    this->spacing = spacing;
}

Color TextElement::getColor() const{
    return tint;
}

void TextElement::setColor(Color color){
    tint = color;
}