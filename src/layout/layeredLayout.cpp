#include "layeredLayout.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

#ifdef DEBUG_LAYOUT_SIZES
#include <iostream>
#endif

const LayoutConstraint LayeredLayout::Constraints::FRONT(static_cast<int>(ConstraintsEnum::FRONT));
const LayoutConstraint LayeredLayout::Constraints::BACK(static_cast<int>(ConstraintsEnum::BACK));

LayeredLayout::LayeredLayout(){

}

void LayeredLayout::addComponent(Component& component, const LayoutConstraint& constraint){
    switch(static_cast<ConstraintsEnum>(constraint.getValue())){
    case ConstraintsEnum::FRONT:
        content.push_back(component);
        break;
    case ConstraintsEnum::BACK:
        content.insert(content.cbegin(), component);
        break;
    default:
        throw std::invalid_argument(std::to_string(constraint.getValue()));
    }
}

void LayeredLayout::removeComponent(const LayoutConstraint& constraint){
    switch(static_cast<ConstraintsEnum>(constraint.getValue())){
    case ConstraintsEnum::FRONT:
        content.erase(content.cbegin());
        break;
    case ConstraintsEnum::BACK:
        content.pop_back();
        break;
    default:
        throw std::invalid_argument(std::to_string(constraint.getValue()));
    }
}

void LayeredLayout::foreachComponent(const std::function<void(const Component&)>& function) const{
    std::for_each(content.cbegin(), content.cend(), function);
}

void LayeredLayout::layout(Component& managed){
    const Vector2 containerPos = managed.getPos();
    const Vector2 containerSize = managed.getSize();

#ifdef DEBUG_LAYOUT_SIZES
    std::cerr<<"LayeredLayout{"<<containerPos.x<<", "<<containerPos.y<<"}, {"
    <<containerSize.x<<", "<<containerSize.y<<"}\n";
#endif

    for(Component& current : content){
        current.setPos(containerPos);
        current.setSize(containerSize);
        current.layout();
    }
}