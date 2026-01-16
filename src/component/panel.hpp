#pragma once

#include "container.hpp"
#include <raylib.h>

class Panel : public Container{

private:
    Color backgroundColor = LIGHTGRAY;

public:
    Panel(LayoutManager& layoutManager);

    Color getBackgroundColor() const;
    void setBackgroundColor(Color color);

    virtual void draw() const override;

    virtual void toStr(std::ostream& stream) const override;

};