#include "inputListener.hpp"

InputListener::InputListener(const std::function<bool(int)>& inputTest, const int inputCode, const std::function<void()> action)
:inputTest(inputTest),inputCode(inputCode),action(action){

}

void InputListener::onEvent(Event&) const{
    if(inputTest(inputCode)){
        action();
    }
}