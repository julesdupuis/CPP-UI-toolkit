#include "listener.hpp"
#include <functional>

Listener::Listener(const std::function<void()> action):
callback(action){

}

void Listener::onEvent() const{
    callback();
}