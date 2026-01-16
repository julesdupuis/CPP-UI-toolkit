#pragma once

#include "component.hpp"
#include "../model/textModel.hpp"

class Label : public Component{

private:
    TextModel& textModel;

public:
    Label(TextModel& text);

    TextModel& getTextModel() const;
    void setTextModel(TextModel& model);

    virtual void layout() override;

    virtual void draw() const override;
    virtual void fit() override;

};