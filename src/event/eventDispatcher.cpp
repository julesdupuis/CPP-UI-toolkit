#include "eventDispatcher.hpp"
#include "event.hpp"
#include <raylib.h>

void EventDispatcher::dispatch(){
    Event e;
    fireEvent(e);
}

void EventDispatcher::addInputListener(Listener& listener){
    subscribe(listener);
}

void EventDispatcher::removeInputListener(Listener& listener){
    unsubscribe(listener);
}
