#include "stackLayout.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

StackLayout::StackLayout(bool vertical):OrientedLayout(vertical){

}

void StackLayout::addComponent(Component& component, int constraint){
    if(constraint < static_cast<int>(Constraints::LAST)){
        throw  std::invalid_argument(std::to_string(constraint));
    }
    if(constraint == static_cast<int>(Constraints::LAST)){
        content.push_back(component);
        return;
    }
    content.insert(content.begin()+constraint, component);
}

void StackLayout::removeComponent(Component&, int constraint){
    if(constraint < static_cast<int>(Constraints::LAST)){
        throw  std::invalid_argument(std::to_string(constraint));
    }
    if(constraint == static_cast<int>(Constraints::LAST)){
        content.pop_back();
        return;
    }
    content.erase(content.begin()+constraint);
}

Bag<Component*> StackLayout::getComponents(){
    Bag<Component*> bag;
    std::for_each(content.begin(), content.end(), [&bag](Component& component){
        bag.add(&component);
    });
    return bag;
};

void StackLayout::layout(Component& managed){
    const Vector2 containerPos = managed.getPos();
    const Vector2 containerSize = managed.getSize();

    Vector2 currentPos = containerPos;
    if(isVertical()){
        for(Component current : content){
            Vector2 currentSize = current.getSize();
            currentSize.x = containerSize.x;
            current.setPos(currentPos);
            currentPos.y += currentSize.y;
            current.setSize(currentSize);
            current.layout();
        }
    }else{
        for(Component current : content){
            Vector2 currentSize = current.getSize();
            currentSize.y = containerSize.y;
            current.setPos(currentPos);
            currentPos.x += currentSize.x;
            current.setSize(currentSize);
            current.layout();
        }
    }
}