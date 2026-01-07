#include "inputListener.hpp"
#include "../utils/singleton.hpp"

InputListener::InputListener(const std::function<bool()>& inputTest,
    const std::function<void()>& action,
    const std::function<void()>& actionElse):
dispatcher(Singleton<EventDispatcher>::instance()),
inputTest(inputTest), action(action), actionElse(actionElse){
    dispatcher.addInputListener(*this);
}

InputListener::~InputListener(){
    dispatcher.removeInputListener(*this);
}

void InputListener::onEvent(Event&) const{
    if(inputTest()){
        action();
    }else{
        actionElse();
    }
}