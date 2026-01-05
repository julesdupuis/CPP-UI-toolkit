#pragma once

#include "layoutManager.hpp"

class OrientedLayout : public LayoutManager{

private:
    bool vertical;

protected:
    OrientedLayout(bool vertical);

public:
    // virtual ~OrientedLayout()=0;

    bool isVertical() const;
    void setVertical(bool isVertical);

};