#include "textModel.hpp"
#include <string>

TextModel::TextModel(std::string text, Font font):
text(text), font(font){

}

Vector2 TextModel::getSize() const{
    return MeasureTextEx(font, text.c_str(), fontSize, spacing);
}

void TextModel::draw(Vector2 position) const{
    DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
}

std::string TextModel::getText() const{
    return text;
}

void TextModel::setText(std::string text){
    this->text = text;
}

Font TextModel::getFont() const{
    return font;
}

void TextModel::setFont(Font font){
    this->font = font;
}

float TextModel::getFontSize() const{
    return fontSize;
}

void TextModel::setFontSize(float size){
    fontSize = size;
}

float TextModel::getSpacing() const{
    return spacing;
}

void TextModel::setSpacing(float spacing){
    this->spacing = spacing;
}

Color TextModel::getColor() const{
    return tint;
}

void TextModel::setColor(Color color){
    tint = color;
}