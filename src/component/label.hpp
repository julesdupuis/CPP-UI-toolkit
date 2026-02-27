#pragma once

#include "component.hpp"
#include "../model/textModel.hpp"
#include "../renderers/labelRenderer.hpp"
#include <functional>

class Label : public Component{

private:
    TextModel& textModel;
    std::reference_wrapper<LabelRenderer> renderer;

public:
    Label(TextModel& text, TextRenderer& renderer);

    TextModel& getTextModel() const;
    void setTextModel(TextModel& model);

    LabelRenderer& getLabelRenderer() const;
    void setLabelRenderer(LabelRenderer& renderer);

    virtual void draw() const override;
    virtual void layout() override;
    virtual void fit() override;

    virtual void toStr(std::ostream& stream) const override;

};