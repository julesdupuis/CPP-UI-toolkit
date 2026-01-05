#include "action.hpp"

std::string Action::getName() const{
    return name;
}

void Action::setName(std::string name){
    this->name = name;
}