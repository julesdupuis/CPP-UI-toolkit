#pragma once

#include "layoutManager.hpp"
#include <vector>

class LayeredLayout : private LayoutManager{

private:
    std::vector<Component> content;

public:
    LayeredLayout();

    virtual void addComponent(Component& component, int constraint) override;
    virtual void removeComponent(Component& component, int constraint) override;

    virtual void layout(Component& managed) override;

};