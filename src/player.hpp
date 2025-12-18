#pragma once

#include "event/inputListener.hpp"
#include <raylib.h>

class Player{

private:
    Vector2 position;
    float speed;

public:
    Player(Vector2 position = {0, 0}, float speed = 100);
    void move(int x, int y);
    const Vector2 getPos() const;
    float getSpeed() const;

};

class PlayerListener{

private:
    Player& player;
    InputListener upListener;
    InputListener downListener;
    InputListener leftListener;
    InputListener rightListener;

public:
    PlayerListener(Player& player);

};