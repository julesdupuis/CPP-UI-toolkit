#include "stackLayout.hpp"
#include "layoutManager.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

#ifdef DEBUG_LAYOUT_SIZES
#include <iostream>
#endif

const LayoutConstraint StackLayout::Constraints::FIRST(static_cast<int>(ConstraintsEnum::FIRST));
const LayoutConstraint StackLayout::Constraints::LAST(static_cast<int>(ConstraintsEnum::LAST));

StackLayout::StackLayout(bool vertical):OrientedLayout(vertical){

}

void StackLayout::addComponent(Component& component, const LayoutConstraint& constraint){
    switch(static_cast<ConstraintsEnum>(constraint.getValue())){
    case ConstraintsEnum::FIRST:
        content.insert(content.cbegin(), component);
        break;
    case ConstraintsEnum::LAST:
        content.push_back(component);
        break;
    default:
        throw std::invalid_argument(std::to_string(constraint.getValue()));
    }
}

void StackLayout::removeComponent(const LayoutConstraint& constraint){
    switch(static_cast<ConstraintsEnum>(constraint.getValue())){
    case ConstraintsEnum::FIRST:
        content.erase(content.cbegin());
        break;
    case ConstraintsEnum::LAST:
        content.pop_back();
        break;
    default:
        throw std::invalid_argument(std::to_string(constraint.getValue()));
    }
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