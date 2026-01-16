#include "freeLayout.hpp"

FreeLayout::FreeLayout(){

}

void FreeLayout::layout(Component& /*managed*/){
    // const Vector2 containerPos = managed.getPos();
    // const Vector2 containerSize = managed.getSize();

    for(Component& current : content){
        // current.setPos(containerPos);
        // current.setSize(containerSize);
        current.layout();
    }
}

void FreeLayout::toStr(std::ostream& stream) const{
    stream<<"FreeLayout : ";
    LayoutManager::toStr(stream);
}