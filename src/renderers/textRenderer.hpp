#pragma once

#include "../model/textModel.hpp"

class TextRenderer{

private:
    Font font;
    float fontSize = 10;
    float spacing = 1;
    Color tint = BLACK;

    int cursorWidth = 5;

public:
    TextRenderer(Font font = GetFontDefault());

    void drawText(Vector2 position, const TextModel& text) const;
    void drawCursor(Vector2 position) const;

    Vector2 getSize(const TextModel& text) const;

    Font getFont() const;
    void setFont(Font font);

    float getFontSize() const;
    void setFontSize(float size);

    float getSpacing() const;
    void setSpacing(float spacing);

    Color getColor() const;
    void setColor(Color color);

};