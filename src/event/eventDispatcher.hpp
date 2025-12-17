#pragma once

#include "listener.hpp"
#include "observable.hpp"

class EventDispatcher : private Observable{

public:
    void dispatch();

    void addInputListener(Listener& listener);
    void removeInputListener(Listener& listener);

};