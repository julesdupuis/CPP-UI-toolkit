#include "orientedComponent.hpp"

OrientedComponent::OrientedComponent(){

}

bool OrientedComponent::isVertical() const{
    return vertical;
}

void OrientedComponent::setVertical(bool isVertical){
    vertical = isVertical;
}