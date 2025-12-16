#pragma once

#include "listener.hpp"
#include "../utils/bag.hpp"

class EventDispatcher{

private:
    Bag<Listener> eventCatchers;

public:
    EventDispatcher();
    ~EventDispatcher();

    void dispatch();

    void addInputListener(const Listener& listener);
    void removeInputListener(const Listener& listener);

};