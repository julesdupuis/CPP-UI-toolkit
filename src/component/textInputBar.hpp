#pragma once

#include "label.hpp"
#include "../model/textModel.hpp"
#include "../event/frameListener.hpp"
#include "../event/timer.hpp"
#include "../event/inputListener.hpp"

class TextInputBar : public Label{

private:
    TextModel phantomText;

    const int cursorWidth = 5;

    FrameListener keyboardInputListener;
    InputListener erasingPressListener;
    InputListener erasingReleaseListener;
    Timer timerBeforeContinuousErasing;
    InputListener continuousEraserListener;
    Timer eraser;

public:
    TextInputBar(TextModel& text, std::string phantomText="");

    std::string getPhantomText() const;
    void setPhantomText(std::string text);

    virtual void draw() const override;

    virtual void toStr(std::ostream& stream) const override;

};