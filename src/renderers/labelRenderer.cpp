#include "labelRenderer.hpp"

LabelRenderer::LabelRenderer(TextRenderer& renderer):
textRenderer(renderer){

}

TextRenderer& LabelRenderer::getTextRenderer() const{
    return textRenderer;
}

void LabelRenderer::setTextRenderer(TextRenderer& renderer){
    textRenderer = renderer;
}

void LabelRenderer::draw() const{

}