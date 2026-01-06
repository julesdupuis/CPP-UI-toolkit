#pragma once

#include "../component/component.hpp"
#include "../utils/bag.hpp"

template class Bag<Component*>;

class LayoutManager{

private:

protected:
    LayoutManager();

public:
    // virtual ~LayoutManager()=0;

    virtual void addComponent(Component& component, int constraint);
    virtual void removeComponent(Component& component, int constraint);
    virtual Bag<Component*> getComponents();

    virtual void layout(Component& managed);

};