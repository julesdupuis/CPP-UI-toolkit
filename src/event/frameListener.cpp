#include "frameListener.hpp"
#include "../utils/singleton.hpp"

FrameListener::FrameListener(const std::function<void()>& action):
dispatcher(Singleton<EventDispatcher>::instance()),
action(action){
    dispatcher.addInputListener(*this);
}

FrameListener::~FrameListener(){
    dispatcher.removeInputListener(*this);
}

void FrameListener::onEvent(Event&) const{
    action();
}