#include "player.hpp"

Player::Player(Vector2 position, float speed):position(position),speed(speed){

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

PlayerListener::PlayerListener(Player& player):
player(player),
upListener([]{return IsKeyDown(KeyboardKey::KEY_UP);},
[this](){
    this->player.move(0, -this->player.getSpeed());
}),
downListener([]{return IsKeyDown(KeyboardKey::KEY_DOWN);},
[this](){
    this->player.move(0, this->player.getSpeed());
}),
leftListener([]{return IsKeyDown(KeyboardKey::KEY_LEFT);},
[this](){
    this->player.move(-this->player.getSpeed(), 0);
}),
rightListener([]{return IsKeyDown(KeyboardKey::KEY_RIGHT);},
[this](){
    this->player.move(this->player.getSpeed(), 0);
}){

}
