#include "layeredLayout.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

#ifdef DEBUG_LAYOUT_SIZES
#include <iostream>
#endif

LayeredLayout::LayeredLayout(){

}

void LayeredLayout::addComponent(Component& component, int constraint){
    if(constraint < static_cast<int>(Constraints::FRONT)){
        throw  std::invalid_argument(std::to_string(constraint));
    }
    if(constraint == static_cast<int>(Constraints::FRONT)){
        content.push_back(component);
        return;
    }
    content.insert(content.begin()+constraint, component);
}

void LayeredLayout::removeComponent(Component& component, int constraint){
    if(constraint < static_cast<int>(Constraints::FRONT)){
        throw  std::invalid_argument(std::to_string(constraint));
    }
    if(constraint == static_cast<int>(Constraints::FRONT)){
        content.pop_back();
        return;
    }
    content.erase(content.begin()+constraint);
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