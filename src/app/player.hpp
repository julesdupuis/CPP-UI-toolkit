#pragma once

#include "../event/inputListener.hpp"
#include <raylib.h>

class PlayerModel{

private:
    Vector2 position;
    float speed;

    Observable movement;

public:
    PlayerModel(Vector2 position = {0, 0}, float speed = 100);

    const Vector2 getPos() const;
    void setPos(Vector2 pos);
    float getSpeed() const;
    void setSpeed(float speed);

    void subscribeMovementListener(Listener& listener);
    void unsubscribeMovementListener(Listener& listener);

};

class Player{

private:
    PlayerModel model;

public:
    Player(Vector2 position = {0, 0}, float speed = 100);

    void move(int x, int y);
    const Vector2 getPos() const;
    float getSpeed() const;

    void subscribeMovementListener(Listener& listener);
    void unsubscribeMovementListener(Listener& listener);

    void draw() const;

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