#include "fpsLabel.hpp"
#include "label.hpp"
#include <raylib.h>
#include <string>

FPSLabel::FPSLabel():
Label(fpsText),
frameListener([this](){
    const int fpsValue = GetFPS();
    fpsText.setText(std::to_string(fpsValue)+" FPS");
    Color fpsColor = goodColor;
    if(fpsValue < warningValue && fpsValue >= lowValue){
        fpsColor = warningColor;
    }else if(fpsValue < lowValue){
        fpsColor = lowColor;
    }
    fpsText.setColor(fpsColor);
}){

}

void FPSLabel::setWarningValue(int value){
    warningValue = value;
}

void FPSLabel::setLowValue(int value){
    lowValue = value;
}

void FPSLabel::setGoodColor(Color color){
    goodColor = color;
}

void FPSLabel::setWarningColor(Color color){
    warningColor = color;
}

void FPSLabel::setLowColor(Color color){
    lowColor = color;
}