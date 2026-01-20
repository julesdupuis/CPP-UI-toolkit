#pragma once

#include "component.hpp"
#include <functional>
#include "../utils/bag.hpp"

template class Bag<const std::function<void()>*>;

class Canva : public Component{

private:
    Bag<const std::function<void()>*> drawings;

public:
    Canva();

    void subscribeDrawing(const std::function<void()>& draw);
    void unsubscribeDrawing(const std::function<void()>& draw);

    virtual void draw() const override;

    virtual void toStr(std::ostream& stream) const override;

};