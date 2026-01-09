#include "borderLayout.hpp"
#include <stdexcept>
#include <string>

#ifdef DEBUG_LAYOUT_SIZES
#include <iostream>
#endif

BorderLayout::BorderLayout(bool vertical):OrientedLayout(vertical){

}

void BorderLayout::addComponent(Component& component, int constraint){
    switch(static_cast<Constraints>(constraint)){
    case Constraints::LEFT:
    // case Constraints::TOP:
        left = &component;
        break;
    case Constraints::RIGHT:
    // case Constraints::BOTTOM:
        right = &component;
        break;
    case Constraints::CENTER:
        center = &component;
        break;
    default:
        throw std::invalid_argument(std::to_string(constraint));
    }
}

void BorderLayout::removeComponent(int constraint){
    switch(static_cast<Constraints>(constraint)){
    case Constraints::LEFT:
    // case Constraints::TOP:
        left = nullptr;
        break;
    case Constraints::RIGHT:
    // case Constraints::BOTTOM:
        right = nullptr;
        break;
    case Constraints::CENTER:
        center = nullptr;
        break;
    default:
        throw std::invalid_argument(std::to_string(constraint));
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

void BorderLayout::layout(Component& managed){
    const Vector2 containerPos = managed.getPos();
    const Vector2 containerSize = managed.getSize();

#ifdef DEBUG_LAYOUT_SIZES
    std::cerr<<"BorderLayout{"<<containerPos.x<<", "<<containerPos.y<<"}, {"
    <<containerSize.x<<", "<<containerSize.y<<"}\n";
#endif

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