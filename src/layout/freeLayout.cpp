#include "freeLayout.hpp"

FreeLayout::FreeLayout(){

}

void FreeLayout::layout(const Component&){
    for(Component& current : content){
        current.layout();
    }
}

void FreeLayout::fit(Component& managed){
    Vector2 maxSize = {0, 0};

    for(Component& current : content){
        current.fit();
        maxSize.x = std::max(maxSize.x, current.getSize().x);
        maxSize.y = std::max(maxSize.y, current.getSize().y);
    }
    managed.setSize(maxSize);
}

void FreeLayout::toStr(std::ostream& stream) const{
    stream<<"FreeLayout : ";
    LayoutManager::toStr(stream);
}