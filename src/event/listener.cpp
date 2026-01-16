#include "listener.hpp"
#include <functional>

Listener::Listener(const std::function<void()> action):
callback(action){

}

bool Listener::isEnabled() const{
    return enabled;
}

void Listener::enable(bool value){
    enabled = value;
}

void Listener::onEvent() const{
    if(isEnabled()){
        callback();
    }
}