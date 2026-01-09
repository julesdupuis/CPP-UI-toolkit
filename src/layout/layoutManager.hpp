#pragma once

#include "../component/component.hpp"
#include <functional>

class LayoutManager{

private:

protected:
    LayoutManager();

public:
    // virtual ~LayoutManager()=0;

    virtual void addComponent(Component& component, int constraint)=0;
    virtual void removeComponent(Component& component, int constraint)=0;

    virtual void foreachComponent(const std::function<void(const Component&)>& function) const=0;

    virtual void layout(Component& managed)=0;

};