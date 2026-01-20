#pragma once

#include "component.hpp"
#include "../model/textModel.hpp"

class Label : public Component{

private:
    TextModel& textModel;

    Vector2 center = {0, 0};

public:
    Label(TextModel& text);

    TextModel& getTextModel() const;
    void setTextModel(TextModel& model);

    virtual void draw() const override;
    virtual void layout() override;
    virtual void fit() override;

    virtual void toStr(std::ostream& stream) const override;

};