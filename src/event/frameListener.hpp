#pragma once

#include "event.hpp"
#include "eventDispatcher.hpp"
#include "listener.hpp"
#include <functional>

class FrameListener : public Listener{

private:
    EventDispatcher& dispatcher;

    const std::function<void()> action;

public:
    FrameListener(const std::function<void()>& action);
    ~FrameListener();

    virtual void onEvent(Event& event) const override;

};