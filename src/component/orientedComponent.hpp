#pragma once

#include "component.hpp"

class OrientedComponent : public Component{

private:
    bool vertical = false;

protected:
    OrientedComponent();

public:
    bool isVertical() const;
    void setVertical(bool isVertical);

};