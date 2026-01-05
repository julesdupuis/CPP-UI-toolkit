#include "orientedLayout.hpp"

OrientedLayout::OrientedLayout(bool vertical):vertical(vertical){

}


bool OrientedLayout::isVertical() const{
    return vertical;
}

void OrientedLayout::setVertical(bool isVertical){
    vertical = isVertical;
}