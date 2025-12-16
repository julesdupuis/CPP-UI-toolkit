#include "inputListener.hpp"

InputListener::InputListener(const std::function<bool(int)>& inputTest, const int inputCode, const Listener& listener)
:inputTest(inputTest),inputCode(inputCode),listener(listener){

}

void InputListener::onEvent(Event& e) const{
    if(inputTest(inputCode)){
        Event e;
        listener.onEvent(e);
    }
}