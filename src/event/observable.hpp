#pragma once

#include "../utils/bag.hpp"
#include "event.hpp"
#include "listener.hpp"

template class Bag<Listener>;

class Observable{

private:
    Bag<Listener> subscribers;

public:
    Observable();
    ~Observable();

    void subscribe(const Listener& listener);
    void unsubscribe(const Listener& listener);

    void fireEvent(Event& e) const;

};