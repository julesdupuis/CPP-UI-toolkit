#pragma once

#include <functional>

class Listener{

private:
    const std::function<void()> callback;
    bool enabled = true;

public:
    Listener(const std::function<void()> callback);

    bool isEnabled() const;
    void enable(bool value);

    void onEvent() const;

};