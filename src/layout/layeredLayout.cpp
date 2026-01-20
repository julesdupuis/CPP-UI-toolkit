#include "layeredLayout.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

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

void LayeredLayout::layout(const Component& managed){
    const Vector2 containerPos = managed.getPos();
    const Vector2 containerSize = managed.getSize();

    for(Component& current : content){
        current.setPos(containerPos);
        current.setSize(containerSize);
        current.layout();
    }
}

void LayeredLayout::fit(Component& managed){
    Vector2 maxSize = {0, 0};

    for(Component& current : content){
        current.fit();
        maxSize.x = std::max(maxSize.x, current.getSize().x);
        maxSize.y = std::max(maxSize.y, current.getSize().y);
    }
    for(Component& current : content){
        current.setSize(maxSize);
    }
    managed.setSize(maxSize);
}

void LayeredLayout::toStr(std::ostream& stream) const{
    stream<<"LayeredLayout : ";
    LayoutManager::toStr(stream);
}