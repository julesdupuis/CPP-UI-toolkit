#include "observable.hpp"
#include "event.hpp"
#include "listener.hpp"

Observable::Observable():subscribers(){

}

Observable::~Observable(){

}

void Observable::subscribe(const Listener& listener){
    subscribers.add(listener);
}

void Observable::unsubscribe(const Listener& listener){
    subscribers.remove(listener);
}

void Observable::fireEvent(Event& e) const{
    subscribers.foreach([&e](const Listener& listener){
        listener.onEvent(e);
    });
}