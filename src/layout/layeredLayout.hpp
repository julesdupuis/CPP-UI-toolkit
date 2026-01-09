#pragma once

#include "layoutManager.hpp"
#include <vector>

class LayeredLayout : public LayoutManager{

public:
    enum class Constraints{
        FRONT = -1,
        BACK = 0,
    };

protected:
    std::vector<std::reference_wrapper<Component>> content;

public:
    LayeredLayout();

    virtual void addComponent(Component& component, int constraint) override;
    virtual void removeComponent(int constraint) override;

    virtual void foreachComponent(const std::function<void(const Component&)>& function) const override;

    virtual void layout(Component& managed) override;

};