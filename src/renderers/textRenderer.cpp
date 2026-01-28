#include "textRenderer.hpp"

TextRenderer::TextRenderer(Font font):
font(font){

}

void TextRenderer::drawText(Vector2 position, const TextModel& text) const{
    DrawTextEx(font, text.getText().c_str(), position, fontSize, spacing, tint);
}

void TextRenderer::drawCursor(Vector2 position) const{
    const Vector2 cursorSize = {static_cast<float>(cursorWidth), fontSize};
    DrawRectangleV(position, cursorSize, BLACK);
}

Vector2 TextRenderer::getSize(const TextModel& text) const{
    return MeasureTextEx(font, text.getText().c_str(), fontSize, spacing);
}

Font TextRenderer::getFont() const{
    return font;
}

void TextRenderer::setFont(Font font){
    this->font = font;
}

float TextRenderer::getFontSize() const{
    return fontSize;
}

void TextRenderer::setFontSize(float size){
    fontSize = size;
}

float TextRenderer::getSpacing() const{
    return spacing;
}

void TextRenderer::setSpacing(float spacing){
    this->spacing = spacing;
}

Color TextRenderer::getColor() const{
    return tint;
}

void TextRenderer::setColor(Color color){
    tint = color;
}