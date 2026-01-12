#pragma once

#include "orientedLayout.hpp"

class BorderLayout : public OrientedLayout{

public:
    struct Constraints{
        static const LayoutConstraint LEFT;
        static const LayoutConstraint RIGHT;
        static const LayoutConstraint TOP; // = LEFT;
        static const LayoutConstraint BOTTOM; // = RIGHT;
        static const LayoutConstraint CENTER;
    };

private:
    enum class ConstraintsEnum{
        LEFT,
        RIGHT,
        TOP = LEFT,
        BOTTOM = RIGHT,
        CENTER,
    };

    Component* left = nullptr;
    Component* right = nullptr;
    Component* center = nullptr;

public:
    BorderLayout(bool vertical = false);

    virtual void addComponent(Component& component, const LayoutConstraint& constraint = Constraints::CENTER) override;
    virtual void removeComponent(const LayoutConstraint& constraint) override;

    virtual void foreachComponent(const std::function<void(const Component&)>& function) const override;

    virtual void layout(Component& managed) override;

    void setVertical(bool isVertical = true);

};