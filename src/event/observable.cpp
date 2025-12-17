#include "observable.hpp"

void Observable::subscribe(Listener& listener){
    subscribers.add(&listener);
}

void Observable::unsubscribe(Listener& listener){
    subscribers.remove(&listener);
}

void Observable::fireEvent(Event& e) const{
    subscribers.foreach([&e](Listener* listener){
        listener->onEvent(e);
    });
}