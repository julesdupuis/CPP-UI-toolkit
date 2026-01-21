#pragma once

#include "frameListener.hpp"

class Timer : public FrameListener{

private:
    float time;
    std::function<void()> callback;

    float accumulatedTime = 0;

public:
    Timer(float time, std::function<void()> onTimer);

    float getTime() const;
    void setTime(float time);

    void start();
    void stop();
    void reset();

};