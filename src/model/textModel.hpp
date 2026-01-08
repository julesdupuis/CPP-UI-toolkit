#pragma once

#include <raylib.h>
#include <string>

class TextModel{

private:
    std::string text;
    Font font;
    float fontSize = 10;
    float spacing = 1;
    Color tint = BLACK;

public:
    TextModel(std::string text, Font font = GetFontDefault());

    Vector2 getSize() const;
    void draw(Vector2 position) const;

    std::string getText() const;
    void setText(std::string text);

    Font getFont() const;
    void setFont(Font font);

    float getFontSize() const;
    void setFontSize(float size);

    float getSpacing() const;
    void setSpacing(float spacing);

    Color getColor() const;
    void setColor(Color color);

};