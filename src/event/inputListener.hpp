#pragma once

#include "frameListener.hpp"
#include <functional>

class InputListener : public FrameListener{

private:
    const std::function<bool()> inputTest;
    const std::function<void()> action;
    const std::function<void()> actionElse;

public:
    InputListener(const std::function<bool()>& inputTest, const std::function<void()>& action, const std::function<void()>& actionElse = []{});

};
