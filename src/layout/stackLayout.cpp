#include "stackLayout.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

#ifdef DEBUG_LAYOUT_SIZES
#include <iostream>
#endif

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

void StackLayout::removeComponent(int constraint){
    if(constraint < static_cast<int>(Constraints::LAST)){
        throw  std::invalid_argument(std::to_string(constraint));
    }
    if(constraint == static_cast<int>(Constraints::LAST)){
        content.pop_back();
        return;
    }
    content.erase(content.begin()+constraint);
}

void StackLayout::foreachComponent(const std::function<void(const Component&)>& function) const{
    std::for_each(content.cbegin(), content.cend(), function);
}

void StackLayout::layout(Component& managed){
    const Vector2 containerPos = managed.getPos();
    const Vector2 containerSize = managed.getSize();

#ifdef DEBUG_LAYOUT_SIZES
    std::cerr<<"StackLayout{"<<containerPos.x<<", "<<containerPos.y<<"}, {"
    <<containerSize.x<<", "<<containerSize.y<<"}\n";
#endif

    Vector2 currentPos = containerPos;
    if(isVertical()){
        for(Component& current : content){
            Vector2 currentSize = current.getSize();
            currentSize.x = containerSize.x;
            current.setPos(currentPos);
            currentPos.y += currentSize.y;
            current.setSize(currentSize);
            current.layout();
        }
    }else{
        for(Component& current : content){
            Vector2 currentSize = current.getSize();
            currentSize.y = containerSize.y;
            current.setPos(currentPos);
            currentPos.x += currentSize.x;
            current.setSize(currentSize);
            current.layout();
        }
    }
}