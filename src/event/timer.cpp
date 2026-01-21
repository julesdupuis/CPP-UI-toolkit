#include "timer.hpp"
#include <raylib.h>

Timer::Timer(float time, std::function<void()> onTimer):
FrameListener([this](){
    accumulatedTime += GetFrameTime();
    if(accumulatedTime >= this->time){
        callback();
        accumulatedTime -= this->time;
    }
}),
time(time),
callback(onTimer){
    enable(false);
}

float Timer::getTime() const{
    return time;
}

void Timer::setTime(float time){
    this->time = time;
}

void Timer::start(){
    enable(true);
}

void Timer::stop(){
    enable(false);
}

void Timer::reset(){
    accumulatedTime = 0;
}