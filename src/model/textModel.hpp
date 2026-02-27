#pragma once

#include <raylib.h>
#include <string>

class TextModel{

private:
    std::string text;

public:
    TextModel(std::string text = "");

    std::string getText() const;
    void setText(std::string text);

};