#include "player.hpp"
#include "event/eventDispatcher.hpp"
#include <raylib.h>

Player::Player():position({0,0}),speed(100){

}

void Player::move(int x, int y){
    position.x += GetFrameTime()*x;
    position.y += GetFrameTime()*y;
}

const Vector2 Player::getPos() const{
    return position;
}

float Player::getSpeed() const{
    return speed;
}

PlayerListener::PlayerListener(Player& player, EventDispatcher& dispatcher):
player(player), dispatcher(dispatcher),
upListener(IsKeyDown, KeyboardKey::KEY_UP, [this](){
    this->player.move(0, -this->player.getSpeed());
}),
downListener(IsKeyDown, KeyboardKey::KEY_DOWN, [this](){
    this->player.move(0, this->player.getSpeed());
}),
leftListener(IsKeyDown, KeyboardKey::KEY_LEFT, [this](){
    this->player.move(-this->player.getSpeed(), 0);
}),
rightListener(IsKeyDown, KeyboardKey::KEY_RIGHT, [this](){
    this->player.move(this->player.getSpeed(), 0);
}){
    dispatcher.addInputListener(&upListener);
    dispatcher.addInputListener(&downListener);
    dispatcher.addInputListener(&leftListener);
    dispatcher.addInputListener(&rightListener);
}

PlayerListener::~PlayerListener(){
    dispatcher.removeInputListener(&upListener);
    dispatcher.removeInputListener(&downListener);
    dispatcher.removeInputListener(&leftListener);
    dispatcher.removeInputListener(&rightListener);
}