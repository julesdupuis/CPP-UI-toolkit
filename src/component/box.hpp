#pragma once

#include "component.hpp"

class Box : public Component{

private:
    Color backgroundColor = LIGHTGRAY;
    Vector4 insets{0, 0, 0, 0};

    Component* component = nullptr;

public:
    Color getBackgroundColor() const;
    void SetBackgroundColor(Color color);

    Vector4 getInsets() const;
    void setInsets(Vector4 insets);

    void add(Component& component);
    void remove();

    virtual void draw() const override;
    virtual void layout() override;
    virtual void fit() override;

};