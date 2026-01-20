#pragma once

#include <ostream>
#include <raylib.h>

class Component{

private:
    Vector2 position;
    Vector2 size;

    bool shown = true;

public:
    Component(Vector2 pos = {0, 0}, Vector2 size = {10, 10});
    virtual ~Component();

    Vector2 getPos() const;
    void setPos(Vector2 pos);
    Vector2 getSize() const;
    void setSize(Vector2 size);

    // Set the size of the component to fit the size of it's content.
    // The underlying components should not be resized here.
    virtual void fit();

    // Set the size and position of underlying components
    // to correctly set the layout.
    // The position and size of this component is considered final
    // from this function perspective.
    virtual void layout();
    virtual void draw() const;

    bool isShown() const;
    void show(bool isShown);

    bool isMouseInside();

    virtual void toStr(std::ostream& stream) const;

};

std::ostream& operator<<(std::ostream& stream, const Vector2& vec);
std::ostream& operator<<(std::ostream& stream, const Component& component);
