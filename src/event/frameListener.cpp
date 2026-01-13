#include "frameListener.hpp"
#include "../utils/singleton.hpp"

FrameListener::FrameListener(const std::function<void()>& action):
Listener(action),
dispatcher(Singleton<EventDispatcher>::instance()){
    dispatcher.addInputListener(*this);
}

FrameListener::~FrameListener(){
    dispatcher.removeInputListener(*this);
}