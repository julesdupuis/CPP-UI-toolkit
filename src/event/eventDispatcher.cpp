#include "eventDispatcher.hpp"

void EventDispatcher::dispatch(){
    fireEvent();
}

void EventDispatcher::addInputListener(Listener& listener){
    subscribe(listener);
}

void EventDispatcher::removeInputListener(Listener& listener){
    unsubscribe(listener);
}
