#include "observable.hpp"

void Observable::subscribe(Listener& listener){
    subscribers.add(&listener);
}

void Observable::unsubscribe(Listener& listener){
    subscribers.remove(&listener);
}

void Observable::fireEvent() const{
    subscribers.foreach([](Listener* listener){
        listener->onEvent();
    });
}