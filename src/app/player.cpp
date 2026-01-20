#include "player.hpp"
#include <string>

PlayerModel::PlayerModel(Vector2 position, float speed):
position(position),speed(speed){

}

const Vector2 PlayerModel::getPos() const{
    return position;
}

void PlayerModel::setPos(Vector2 pos){
    position = pos;
    movement.fireEvent();
}

float PlayerModel::getSpeed() const{
    return speed;
}

void PlayerModel::setSpeed(float speed){
    this->speed = speed;
}

void PlayerModel::subscribeMovementListener(Listener& listener){
    movement.subscribe(listener);
}

void PlayerModel::unsubscribeMovementListener(Listener& listener){
    movement.unsubscribe(listener);
}

Player::Player(Vector2 position, float speed):
model(position, speed){

}

void Player::move(int x, int y){
    Vector2 position = model.getPos();
    position.x += GetFrameTime()*x;
    position.y += GetFrameTime()*y;
    model.setPos(position);
}

const Vector2 Player::getPos() const{
    return model.getPos();
}

float Player::getSpeed() const{
    return model.getSpeed();
}

void Player::subscribeMovementListener(Listener& listener){
    model.subscribeMovementListener(listener);
}
void Player::unsubscribeMovementListener(Listener& listener){
    model.unsubscribeMovementListener(listener);
}

void Player::draw() const{
    const Vector2 pos = getPos();
    const int SIZE = 20;
    const int HALFSIZE = SIZE/2;

    const Vector2 left = {pos.x + HALFSIZE, pos.y + SIZE};
    const Vector2 right = {pos.x - HALFSIZE, pos.y + SIZE};
    // skirt
    DrawTriangle(pos, right, left, RED);
    // top
    DrawLineV(pos, {pos.x, pos.y - SIZE}, RED);
    // head
    const float headRadius = HALFSIZE;
    DrawCircleV({pos.x, pos.y - SIZE - headRadius}, headRadius, RED);
    // arms
    DrawLineV({pos.x - HALFSIZE, pos.y - HALFSIZE}, {pos.x + HALFSIZE, pos.y - HALFSIZE}, RED);
    // legs
    const int legSpacing = 3;
    DrawLineV({pos.x - legSpacing, pos.y + SIZE}, {pos.x - legSpacing, pos.y + SIZE + HALFSIZE}, RED);
    DrawLineV({pos.x + legSpacing, pos.y + SIZE}, {pos.x + legSpacing, pos.y + SIZE + HALFSIZE}, RED);
    // face
    std::string face = "UwU";
    const Vector2 faceSize = MeasureTextEx(GetFontDefault(), face.c_str(), HALFSIZE, 1);
    DrawText(face.c_str(), pos.x - faceSize.x/2, pos.y - SIZE - headRadius - faceSize.y/2, HALFSIZE, BLACK);
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
