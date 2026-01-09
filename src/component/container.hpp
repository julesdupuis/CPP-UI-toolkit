#pragma once

#include "component.hpp"
#include "../layout/layoutManager.hpp"

class Container : public Component{

private:
    LayoutManager& layoutManager;

public:
    Container(LayoutManager& layoutManager);

    void add(Component& component, int constraint);
    void remove(int constraint);

    virtual void layout() override;
    virtual void draw() const override;

};