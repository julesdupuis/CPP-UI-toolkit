#pragma once

#include "orientedLayout.hpp"

class BorderLayout : public OrientedLayout{

public:
    enum class Constraints{
        LEFT,
        RIGHT,
        TOP = LEFT,
        BOTTOM = RIGHT,
        CENTER,
    };

private:
    Component* left = nullptr;
    Component* right = nullptr;
    Component* center = nullptr;

public:
    BorderLayout(bool vertical = false);

    virtual void addComponent(Component& component, int constraint = static_cast<int>(Constraints::CENTER)) override;
    virtual void removeComponent(int constraint) override;

    virtual void foreachComponent(const std::function<void(const Component&)>& function) const override;

    virtual void layout(Component& managed) override;

    void setVertical(bool isVertical = true);

};