#include "eventDispatcher.hpp"
#include "event.hpp"
#include <raylib.h>

void EventDispatcher::dispatch(){
    eventCatchers.foreach([](Listener* listener){
        Event e;
        listener->onEvent(e);
    });
}

void EventDispatcher::addInputListener(Listener* listener){
    eventCatchers.add(listener);
}

void EventDispatcher::removeInputListener(Listener* listener){
    eventCatchers.remove(listener);
}
