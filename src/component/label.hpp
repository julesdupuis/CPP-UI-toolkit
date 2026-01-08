#pragma once

#include "component.hpp"
#include "../model/textModel.hpp"

class Label : public Component{

private:
    TextModel& textModel;

public:
    Label(TextModel& text);

    TextModel& getTextModel() const;

    virtual void draw() const override;
    virtual void fit() override;

};