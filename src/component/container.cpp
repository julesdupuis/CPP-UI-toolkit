#include "container.hpp"

Container::Container(LayoutManager& layoutManager):layoutManager(layoutManager){

}

void Container::add(Component& component, int constraint){
    layoutManager.addComponent(component, constraint);
}

void Container::remove(Component& component, int constraint){
    layoutManager.removeComponent(component, constraint);
}

void Container::layout(){
    layoutManager.layout(*this);
}

void Container::draw() const{
    if(!isShown()){
        return;
    }
    layoutManager.foreachComponent([](const Component& component){
        component.draw();
    });
}