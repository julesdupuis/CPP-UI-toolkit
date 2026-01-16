#include "container.hpp"

Container::Container(LayoutManager& layoutManager):layoutManager(layoutManager){

}

void Container::add(Component& component, const LayoutConstraint& constraint){
    layoutManager.addComponent(component, constraint);
}

void Container::remove(const LayoutConstraint& constraint){
    layoutManager.removeComponent(constraint);
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

void Container::toStr(std::ostream& stream) const{
    Component::toStr(stream);
    stream<<" => ";
    layoutManager.toStr(stream);
}