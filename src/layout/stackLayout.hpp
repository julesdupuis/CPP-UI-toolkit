#pragma once

#include "orientedLayout.hpp"
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
    virtual void removeComponent(int constraint = static_cast<int>(Constraints::LAST)) override;

    virtual void foreachComponent(const std::function<void(const Component&)>& function) const override;

    virtual void layout(Component& managed) override;

    void setVertical(bool isVertical = false);

};