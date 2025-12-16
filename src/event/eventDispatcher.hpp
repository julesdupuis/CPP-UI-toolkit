#pragma once

#include "listener.hpp"
#include "../utils/bag.hpp"

class EventDispatcher{

private:
    Bag<Listener*> eventCatchers;

public:
    void dispatch();

    void addInputListener(Listener* listener);
    void removeInputListener(Listener* listener);

};