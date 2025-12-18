#include "inputListener.hpp"
#include "eventDispatcher.hpp"
#include "../utils/singleton.hpp"

InputListener::InputListener(const std::function<bool(int)>& inputTest, const int inputCode, const std::function<void()> action):
dispatcher(Singleton<EventDispatcher>::instance()),
inputTest(inputTest),inputCode(inputCode),action(action){
    dispatcher.addInputListener(*this);
}

InputListener::~InputListener(){
    dispatcher.removeInputListener(*this);
}

void InputListener::onEvent(Event&) const{
    if(inputTest(inputCode)){
        action();
    }
}