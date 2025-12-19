#pragma once

#include "component.hpp"
#include "drawable.hpp"
#include "../layout/layoutManager.hpp"

class Container : public Drawable{

private:
    LayoutManager& layoutManager;

public:
    Container(LayoutManager& layoutManager);

    void add(Component& component, int constraint);
    void remove(Component& component, int constraint);

    void layout();
    virtual void draw() const override;

};