#include "eventDispatcher.hpp"
#include "event.hpp"
#include "listener.hpp"
#include <raylib.h>

EventDispatcher::EventDispatcher(){

}

EventDispatcher::~EventDispatcher(){

}

void EventDispatcher::dispatch(){
    eventCatchers.foreach([](const Listener& listener){
        Event e;
        listener.onEvent(e);
    });
}

void EventDispatcher::addInputListener(const Listener& listener){
    eventCatchers.add(listener);
}

void EventDispatcher::removeInputListener(const Listener& listener){
    eventCatchers.remove(listener);
}
