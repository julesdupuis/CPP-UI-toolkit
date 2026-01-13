#pragma once

#include "../utils/bag.hpp"
#include "listener.hpp"

template class Bag<Listener*>;

class Observable{

private:
    Bag<Listener*> subscribers;

public:
    void subscribe(Listener& listener);
    void unsubscribe(Listener& listener);

    void fireEvent() const;

};