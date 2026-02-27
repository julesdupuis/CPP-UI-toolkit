#include "textInputBar.hpp"
#include <cstring>

// TODO multiline
TextInputBar::TextInputBar(TextModel& text, TextRenderer& renderer):
Label(text, renderer),
keyboardInputListener([this](){
    std::string originalText = this->getTextModel().getText();
    int codepoint = 0;
    int size = 0;
    while((codepoint = GetCharPressed()) != 0){
        originalText.push_back(*CodepointToUTF8(codepoint, &size));
    }
    this->getTextModel().setText(originalText);
    fit();
    layout();
}),
erasingPressListener([](){
    return IsKeyPressed(KeyboardKey::KEY_BACKSPACE) || IsKeyPressed(KeyboardKey::KEY_DELETE);
},
[this](){
    timerBeforeContinuousErasing.start();
    std::string originalText = this->getTextModel().getText();
    if(originalText.empty()){
        return;
    }
    originalText.pop_back();
    this->getTextModel().setText(originalText);
}),
erasingReleaseListener([](){
    return IsKeyReleased(KeyboardKey::KEY_BACKSPACE) || IsKeyReleased(KeyboardKey::KEY_DELETE);
},
[this](){
    timerBeforeContinuousErasing.stop();
    timerBeforeContinuousErasing.reset();
}),
timerBeforeContinuousErasing(0.5f, [this](){
    timerBeforeContinuousErasing.stop();
    timerBeforeContinuousErasing.reset();
    continuousEraserListener.enable(true);
}),
continuousEraserListener([](){
    return IsKeyDown(KeyboardKey::KEY_BACKSPACE) || IsKeyDown(KeyboardKey::KEY_DELETE);
},
[this](){
    eraser.start();
},
[this](){
    eraser.stop();
    eraser.reset();
    continuousEraserListener.enable(false);
}),
eraser(0.05f, [this](){
    std::string originalText = this->getTextModel().getText();
    if(originalText.empty()){
        return;
    }
    originalText.pop_back();
    this->getTextModel().setText(originalText);
}){
    continuousEraserListener.enable(false);
}

std::string TextInputBar::getPhantomText() const{
    return phantomText.getText();
}

void TextInputBar::setPhantomText(std::string text){
    phantomText.setText(text);
}

void TextInputBar::draw() const{
    if(!isShown()){
        return;
    }
    if(std::strlen(getTextModel().getText().c_str()) <= 0){
        getTextRenderer().drawText(getPos(), phantomText);
    }else{
        Label::draw();
    }
    // cursor drawing
    if(static_cast<int>(GetTime())%2 == 0){ // TODO component selection
        return;
    }
    const Vector2 pos = getPos();
    const Vector2 textSize = getTextRenderer().getSize(getTextModel());
    const Vector2 cursorPos = {pos.x + textSize.x, pos.y};
    getTextRenderer().drawCursor(cursorPos);
}

void TextInputBar::toStr(std::ostream& stream) const{
    stream<<"TextInputBar : ";
    Component::toStr(stream);
}