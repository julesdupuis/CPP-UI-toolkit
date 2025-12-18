#pragma once

#include "event.hpp"
#include "eventDispatcher.hpp"
#include "listener.hpp"
#include <functional>

class InputListener : public Listener{

private:
    EventDispatcher& dispatcher;

    const std::function<bool()> inputTest;
    const std::function<void()> action;

public:
    InputListener(const std::function<bool()>& inputTest, const std::function<void()> action);
    ~InputListener();

    virtual void onEvent(Event& e) const override;

};
