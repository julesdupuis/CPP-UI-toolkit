#pragma once

#include "orientedLayout.hpp"
#include <vector>

class StackLayout : public OrientedLayout{

public:
    struct Constraints{
        static const LayoutConstraint LAST;
        static const LayoutConstraint FIRST;
    };

private:
    enum class ConstraintsEnum{
        LAST,
        FIRST,
    };

    std::vector<std::reference_wrapper<Component>> content;

public:
    StackLayout(bool vertical = true);

    virtual void addComponent(Component& component, const LayoutConstraint& constraint = Constraints::LAST) override;
    virtual void removeComponent(const LayoutConstraint& constraint = Constraints::LAST) override;

    virtual void foreachComponent(const std::function<void(const Component&)>& function) const override;

    virtual void layout(Component& managed) override;

    void setVertical(bool isVertical = false);

};