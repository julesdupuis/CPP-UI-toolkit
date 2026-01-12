#pragma once

#include "layoutManager.hpp"
#include <vector>

class LayeredLayout : public LayoutManager{

public:
    struct Constraints{
        static const LayoutConstraint FRONT;
        static const LayoutConstraint BACK;
    };

private:
    enum class ConstraintsEnum{
        FRONT,
        BACK,
    };

protected:
    std::vector<std::reference_wrapper<Component>> content;

public:
    LayeredLayout();

    virtual void addComponent(Component& component, const LayoutConstraint& constraint) override;
    virtual void removeComponent(const LayoutConstraint& constraint) override;

    virtual void foreachComponent(const std::function<void(const Component&)>& function) const override;

    virtual void layout(Component& managed) override;

};