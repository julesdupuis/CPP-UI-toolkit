#pragma once

#include <functional>

class Listener{

private:
    const std::function<void()> callback;

public:
    Listener(const std::function<void()> callback);

    void onEvent() const;

};