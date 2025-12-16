#pragma once

#include "event.hpp"
#include "listener.hpp"
#include <functional>

class InputListener : public Listener{

private:
    std::function<bool(int)> inputTest;
    const int inputCode;
    const Listener& listener;

public:
    InputListener(const std::function<bool(int)>& inputTest, const int inputCode, const Listener& listener);

    virtual void onEvent(Event& e) const override;

};
