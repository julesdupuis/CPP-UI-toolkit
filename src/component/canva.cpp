#include "canva.hpp"

Canva::Canva(){

}

void Canva::subscribeDrawing(const std::function<void()>& draw){
    drawings.add(&draw);
}

void Canva::unsubscribeDrawing(const std::function<void()>& draw){
    drawings.remove(&draw);
}

void Canva::draw() const{
    drawings.foreach([](const std::function<void()>* const& drawFunction){
        (*drawFunction)();
    });
}

void Canva::toStr(std::ostream& stream) const{
    stream<<"Canva : ";
    Component::toStr(stream);
}