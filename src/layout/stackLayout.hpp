#pragma once

#include "orientedLayout.hpp"
#include <vector>

class StackLayout : private OrientedLayout{

private:
    std::vector<Component> content;

public:
    StackLayout(bool vertical = true);

    virtual void addComponent(Component& component, int constraint) override;
    virtual void removeComponent(Component& component, int constraint) override;

    virtual void layout(Component& managed) override;

    void setVertical(bool isVertical = false);

};