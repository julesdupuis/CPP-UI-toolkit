#include "inputListener.hpp"
#include "../utils/singleton.hpp"
#include "listener.hpp"

InputListener::InputListener(const std::function<bool()>& inputTest,
    const std::function<void()>& action,
    const std::function<void()>& actionElse):
    Listener([this](){
    if(this->inputTest()){
        this->action();
    }else{
        this->actionElse();
    }
}),
dispatcher(Singleton<EventDispatcher>::instance()),
inputTest(inputTest), action(action), actionElse(actionElse){
    dispatcher.addInputListener(*this);
}

InputListener::~InputListener(){
    dispatcher.removeInputListener(*this);
}