#pragma once

#include "../component/component.hpp"

class LayoutManager{

private:

public:
    virtual ~LayoutManager()=0;

    virtual void addComponent(Component& component, int constraint);
    virtual void removeComponent(Component& component, int constraint);

    virtual void layout(Component& managed);

};