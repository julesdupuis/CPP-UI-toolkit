#include "stackLayout.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

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

void StackLayout::layout(const Component& managed){
    const Vector2 containerPos = managed.getPos();
    const Vector2 containerSize = managed.getSize();

    Vector2 currentPos = containerPos;
    if(isVertical()){
        for(Component& current : content){
            Vector2 currentSize = current.getSize();
            current.setPos(currentPos);
            currentPos.y += currentSize.y;

            currentSize.x = containerSize.x;
            current.setSize(currentSize);

            current.layout();
        }
    }else{
        for(Component& current : content){
            Vector2 currentSize = current.getSize();
            current.setPos(currentPos);
            currentPos.x += currentSize.x;

            currentSize.y = containerSize.y;
            current.setSize(currentSize);

            current.layout();
        }
    }
}

void StackLayout::fit(Component& managed){
    Vector2 maxSize = {0, 0};

    if(isVertical()){
        for(Component& current : content){
            current.fit();
            maxSize.x = std::max(maxSize.x, current.getSize().x);
        }
        for(Component& current : content){
            Vector2 currentSize = current.getSize();
            maxSize.y += currentSize.y;
            currentSize.x = maxSize.x;
            current.setSize(currentSize);
        }
        managed.setSize(maxSize);
    }else{
        for(Component& current : content){
            current.fit();
            maxSize.y = std::max(maxSize.y, current.getSize().y);
        }
        for(Component& current : content){
            Vector2 currentSize = current.getSize();
            maxSize.x += currentSize.x;
            currentSize.y = maxSize.y;
            current.setSize(currentSize);
        }
        managed.setSize(maxSize);
    }
}

void StackLayout::toStr(std::ostream& stream) const{
    stream<<"StackLayout : ";
    LayoutManager::toStr(stream);
}