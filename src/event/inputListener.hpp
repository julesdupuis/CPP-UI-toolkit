#pragma once

#include "event.hpp"
#include "listener.hpp"
#include <functional>

class InputListener : public Listener{

private:
    const std::function<bool(int)> inputTest;
    const int inputCode;
    const std::function<void()> action;

public:
    InputListener(const std::function<bool(int)>& inputTest, const int inputCode, const std::function<void()> action);

    virtual void onEvent(Event& e) const override;

};
