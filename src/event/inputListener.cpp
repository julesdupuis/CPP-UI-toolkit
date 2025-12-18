#include "inputListener.hpp"
#include "../utils/singleton.hpp"

InputListener::InputListener(const std::function<bool()>& inputTest, const std::function<void()> action):
dispatcher(Singleton<EventDispatcher>::instance()),
inputTest(inputTest),action(action){
    dispatcher.addInputListener(*this);
}

InputListener::~InputListener(){
    dispatcher.removeInputListener(*this);
}

void InputListener::onEvent(Event&) const{
    if(inputTest()){
        action();
    }
}