#pragma once

#include "component.hpp"
#include "../utils/textElement.hpp"

class Label : public Component{

private:
    TextElement text;

public:
    Label(TextElement&& text);

    TextElement& getText() const;

    virtual void draw() const override;

};