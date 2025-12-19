#pragma once

#include "layoutManager.hpp"

class OrientedLayout : protected LayoutManager{

private:
    bool vertical;

public:
    OrientedLayout(bool vertical);
    ~OrientedLayout()=0;

    bool isVertical() const;
    void setVertical(bool isVertical);

};