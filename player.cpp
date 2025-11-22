#include "player.h"

Player::Player(float x, float y){
    position = {x,y};
    speed = 300.0f;
    size = 5;
    default_acceleration = 10.0f;
    acceleration = default_acceleration;
    canJump = false;
    isJumping = false;
}

void Player::Move(float dx, float dy, float deltaTime){
    position.x += dx * speed * deltaTime;
    position.y += dy * speed * deltaTime;
}

void Player::Fall(float deltaTime){
    if (!isJumping){
        position.y += acceleration * deltaTime;
        acceleration += 50;
    }
}

void Player::Jump(float deltaTime){
    acceleration -=50;
    position.y += acceleration * deltaTime;
}