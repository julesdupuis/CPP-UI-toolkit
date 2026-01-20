#pragma once

#include "component.hpp"
#include "../layout/layoutManager.hpp"

class Container : public Component{

private:
    LayoutManager& layoutManager;

public:
    Container(LayoutManager& layoutManager);

    void add(Component& component, const LayoutConstraint& constraint);
    void remove(const LayoutConstraint& constraint);

    virtual void layout() override;
    virtual void fit() override;
    virtual void draw() const override;

    virtual void toStr(std::ostream& stream) const override;
};