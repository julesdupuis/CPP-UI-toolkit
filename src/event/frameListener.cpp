#include "frameListener.hpp"
#include "../utils/globalAccessor.hpp"

FrameListener::FrameListener(const std::function<void()>& action):
Listener(action),
dispatcher(GlobalAccessor<EventDispatcher>::instance()){
    dispatcher.addInputListener(*this);
}

FrameListener::~FrameListener(){
    dispatcher.removeInputListener(*this);
}