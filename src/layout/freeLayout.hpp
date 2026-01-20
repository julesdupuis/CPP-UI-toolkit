#pragma once

#include "layeredLayout.hpp"

class FreeLayout : public LayeredLayout{

private:

public:
    FreeLayout();

    virtual void layout(const Component& managed) override;
    virtual void fit(Component& managed) override;

    virtual void toStr(std::ostream& stream) const override;
};