#include "container.hpp"
#include "component.hpp"

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
    ClearBackground(LIGHTGRAY);
    Bag<Component*> components = layoutManager.getComponents();
    components.foreach([](Component*const& component){
        component->draw();
    });
}