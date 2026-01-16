#include "inputListener.hpp"

InputListener::InputListener(const std::function<bool()>& inputTest,
    const std::function<void()>& action,
    const std::function<void()>& actionElse):
    FrameListener([this](){
    if(this->inputTest()){
        this->action();
    }else{
        this->actionElse();
    }
}),
inputTest(inputTest), action(action), actionElse(actionElse){

}