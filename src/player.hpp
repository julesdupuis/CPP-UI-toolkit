#pragma once

#include "event/eventDispatcher.hpp"
#include "event/inputListener.hpp"
#include <raylib.h>

class Player{

private:
    Vector2 position;
    float speed;

public:
    Player();
    void move(int x, int y);
    const Vector2 getPos() const;
    float getSpeed() const;

};

class PlayerListener{

private:
    Player& player;
    EventDispatcher& dispatcher;
    InputListener upListener;
    InputListener downListener;
    InputListener leftListener;
    InputListener rightListener;

public:
    PlayerListener(Player& player, EventDispatcher& dispatcher);
    ~PlayerListener();

};