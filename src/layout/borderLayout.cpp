#include "borderLayout.hpp"
#include <stdexcept>
#include <string>

const LayoutConstraint BorderLayout::Constraints::LEFT(static_cast<int>(ConstraintsEnum::LEFT));
const LayoutConstraint BorderLayout::Constraints::RIGHT(static_cast<int>(ConstraintsEnum::RIGHT));
const LayoutConstraint BorderLayout::Constraints::TOP(static_cast<int>(ConstraintsEnum::TOP)); // = LEFT;
const LayoutConstraint BorderLayout::Constraints::BOTTOM(static_cast<int>(ConstraintsEnum::BOTTOM)); // = RIGHT;
const LayoutConstraint BorderLayout::Constraints::CENTER(static_cast<int>(ConstraintsEnum::CENTER));

BorderLayout::BorderLayout(bool vertical):OrientedLayout(vertical){

}

void BorderLayout::addComponent(Component& component, const LayoutConstraint& constraint){
    switch(static_cast<ConstraintsEnum>(constraint.getValue())){
    case ConstraintsEnum::LEFT:
    // case Constraints::TOP:
        left = &component;
        break;
    case ConstraintsEnum::RIGHT:
    // case Constraints::BOTTOM:
        right = &component;
        break;
    case ConstraintsEnum::CENTER:
        center = &component;
        break;
    default:
        throw std::invalid_argument(std::to_string(constraint.getValue()));
    }
}

void BorderLayout::removeComponent(const LayoutConstraint& constraint){
    switch(static_cast<ConstraintsEnum>(constraint.getValue())){
    case ConstraintsEnum::LEFT:
    // case Constraints::TOP:
        left = nullptr;
        break;
    case ConstraintsEnum::RIGHT:
    // case Constraints::BOTTOM:
        right = nullptr;
        break;
    case ConstraintsEnum::CENTER:
        center = nullptr;
        break;
    default:
        throw std::invalid_argument(std::to_string(constraint.getValue()));
    }
}

void BorderLayout::foreachComponent(const std::function<void(const Component&)>& function) const{
    if(left != nullptr){
        function(*left);
    }
    if(right != nullptr){
        function(*right);
    }
    if(center != nullptr){
        function(*center);
    }
}

void BorderLayout::layout(const Component& managed){
    const Vector2 containerPos = managed.getPos();
    const Vector2 containerSize = managed.getSize();

    if(left != nullptr){
        Vector2 pos = containerPos;
        Vector2 size = left->getSize();

        if(isVertical()){
            size.x = containerSize.x;
            // size.y does not change
        }else{
            // size.x does not change
            size.y = containerSize.y;
        }
        left->setPos(pos);
        left->setSize(size);
        left->layout();
    }
    if(right != nullptr){
        Vector2 pos = containerPos;
        Vector2 size = right->getSize();

        if(isVertical()){
            size.x = containerSize.x;
            // size.y does not change

            // pos.x stays 0 relative to container
            pos.y = containerPos.y + containerSize.y - size.y;
        }else{
            // size.x does not change
            size.y = containerSize.y;

            pos.x = containerPos.x + containerSize.x - size.x;
            // pos.y stays 0 relative to container
        }
        right->setPos(pos);
        right->setSize(size);
        right->layout();
    }
    if(center != nullptr){
        Vector2 pos = containerPos;
        Vector2 size = containerSize;

        if(isVertical()){
            if(left != nullptr){
                // pos.x stays 0 relative to container
                pos.y += left->getSize().y;

                // size.x does not change
                size.y -= left->getSize().y;
            }
            if(right != nullptr){
                // size.x does not change
                size.y -= right->getSize().y;
            }
        }else{
            if(left != nullptr){
                pos.x += left->getSize().x;
                // pos.y stays 0 relative to container

                size.x -= left->getSize().x;
                // size.y does not change
            }
            if(right != nullptr){
                size.x -= right->getSize().x;
                // size.y does not change
            }
        }
        center->setPos(pos);
        center->setSize(size);
        center->layout();
    }
}

void BorderLayout::fit(Component& managed){
    Vector2 containerSize = {0, 0};

    if(left != nullptr){
        left->fit();
        const Vector2 size = left->getSize();

        if(isVertical()){
            containerSize.y += size.y;
            containerSize.x = std::max(containerSize.x, size.x);
        }else{
            containerSize.x += size.x;
            containerSize.y = std::max(containerSize.y, size.y);
        }
    }
    if(right != nullptr){
        right->fit();
        const Vector2 size = right->getSize();

        if(isVertical()){
            containerSize.y += size.y;
            containerSize.x = std::max(containerSize.x, size.x);
        }else{
            containerSize.x += size.x;
            containerSize.y = std::max(containerSize.y, size.y);
        }
    }
    if(center != nullptr){
        center->fit();
        const Vector2 size = center->getSize();

        if(isVertical()){
            containerSize.y += size.y;
            containerSize.x = std::max(containerSize.x, size.x);
        }else{
            containerSize.x += size.x;
            containerSize.y = std::max(containerSize.y, size.y);
        }
    }
    managed.setSize(containerSize);
}

void BorderLayout::toStr(std::ostream& stream) const{
    stream<<"BorderLayout : ";
    LayoutManager::toStr(stream);
}