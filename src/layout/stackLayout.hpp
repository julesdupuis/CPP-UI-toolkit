#pragma once

#include "orientedLayout.hpp"
#include <functional>
#include <vector>

class StackLayout : public OrientedLayout{

public:
    enum class Constraints{
        LAST = -1,
        FIRST = 0,
    };

private:
    std::vector<std::reference_wrapper<Component>> content;

public:
    StackLayout(bool vertical = true);

    virtual void addComponent(Component& component, int constraint = static_cast<int>(Constraints::LAST)) override;
    virtual void removeComponent(Component& component, int constraint = static_cast<int>(Constraints::LAST)) override;
    virtual Bag<Component*> getComponents() override;

    virtual void layout(Component& managed) override;

    void setVertical(bool isVertical = false);

};