#pragma once

#include "eventDispatcher.hpp"
#include "listener.hpp"
#include <functional>

class FrameListener : public Listener{

private:
    EventDispatcher& dispatcher;

public:
    FrameListener(const std::function<void()>& action);
    ~FrameListener();

};