#include "player.h"

Player::Player(float x, float y){
    position = {x,y};
    speed = 300.0f;
    jumpHeight = 10.0f;
    size = 5;
    default_acceleration = 10.0f;
    acceleration = default_acceleration;
    inair = false;
}

void Player::Move(float dx, float dy, float deltaTime){
    position.x += dx * speed * deltaTime;
    position.y += dy * speed * deltaTime;
}

void Player::Fall(float deltaTime){
    position.y += acceleration * deltaTime;
    acceleration += 50;
}

void Player::Jump(float deltaTime){

}