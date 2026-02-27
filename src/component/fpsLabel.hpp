#pragma once

#include "label.hpp"
#include "../event/frameListener.hpp"
#include <raylib.h>

class FPSLabel : public Label{

private:
    TextModel fpsText;
    TextRenderer fpsTextRenderer;
    FrameListener frameListener;

    int warningValue = 30;
    int lowValue = 15;

    Color goodColor = LIME;
    Color warningColor = ORANGE;
    Color lowColor = RED;

public:
    FPSLabel();

    void setWarningValue(int value);
    void setLowValue(int value);

    void setGoodColor(Color color);
    void setWarningColor(Color color);
    void setLowColor(Color color);

};