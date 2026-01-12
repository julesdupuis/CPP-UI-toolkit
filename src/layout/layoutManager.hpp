#pragma once

#include "../component/component.hpp"
#include <functional>

class LayoutConstraint{

private:
    const int value;

public:
    LayoutConstraint(int value);

    int getValue() const;

};

class LayoutManager{

private:

protected:
    LayoutManager();

public:
    // virtual ~LayoutManager()=0;

    virtual void addComponent(Component& component, const LayoutConstraint& constraint)=0;
    virtual void removeComponent(const LayoutConstraint& constraint)=0;

    virtual void foreachComponent(const std::function<void(const Component&)>& function) const=0;

    virtual void layout(Component& managed)=0;

};