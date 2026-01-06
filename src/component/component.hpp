#pragma once

#include <raylib.h>

class Component{

private:
    Vector2 position;
    Vector2 size;

    bool shown = true;

public:
    Component(Vector2 pos = {0, 0}, Vector2 size = {10, 10});

    Vector2 getPos() const;
    void setPos(Vector2 pos);
    Vector2 getSize() const;
    void setSize(Vector2 size);
    virtual void fit();

    virtual void draw() const;
    void show(bool isShown);

};