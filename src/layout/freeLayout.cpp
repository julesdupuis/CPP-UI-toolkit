#include "freeLayout.hpp"

#ifdef DEBUG_LAYOUT_SIZES
#include <iostream>
#endif

FreeLayout::FreeLayout(){

}

void FreeLayout::layout(Component& /*managed*/){
    // const Vector2 containerPos = managed.getPos();
    // const Vector2 containerSize = managed.getSize();

#ifdef DEBUG_LAYOUT_SIZES
    std::cerr<<"FreeLayout{"<<containerPos.x<<", "<<containerPos.y<<"}, {"
    <<containerSize.x<<", "<<containerSize.y<<"}\n";
#endif

    for(Component& current : content){
        // current.setPos(containerPos);
        // current.setSize(containerSize);
        current.layout();
    }
}