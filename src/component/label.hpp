#pragma once

#include "component.hpp"
#include "../model/textModel.hpp"

class Label : public Component{

private:
    TextModel& textModel;

public:
    Label(TextModel&& textModel);

    TextModel& getText() const;

    virtual void draw() const override;

};