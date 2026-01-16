#include "layoutManager.hpp"

LayoutConstraint::LayoutConstraint(int value):value(value){

}

int LayoutConstraint::getValue() const{
    return value;
}

LayoutManager::LayoutManager(){

}

void LayoutManager::toStr(std::ostream& stream) const{
    stream<<"{\n";
    foreachComponent([&stream](const Component& component){
        component.toStr(stream);
        stream<<"\n";
    });
    stream<<"}";
}