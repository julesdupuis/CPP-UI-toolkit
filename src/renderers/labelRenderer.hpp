#pragma once

#include "textRenderer.hpp"
#include <functional>

class LabelRenderer{

private:
    std::reference_wrapper<TextRenderer> textRenderer;

public:
    LabelRenderer(TextRenderer& renderer);

    TextRenderer& getTextRenderer() const;
    void setTextRenderer(TextRenderer& renderer);

    void draw() const;

};