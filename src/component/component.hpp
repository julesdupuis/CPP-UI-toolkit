#pragma once

#include <raylib.h>

class Component{

private:
    Vector2 position;
    Vector2 size;

public:
    Component(Vector2 pos = {10, 10}, Vector2 size = {10, 10});

    Vector2 getPos() const;
    void setPos(Vector2 pos);
    Vector2 getSize() const;
    void setSize(Vector2 size);

};