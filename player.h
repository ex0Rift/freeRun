#pragma once
#include "raylib.h"

class Player{
public:
    Vector2 position;
    float speed;
    int size;
    float acceleration;
    float default_acceleration;
    bool canJump;
    bool isJumping;

    Player(float x, float y);
    void Move(float dx, float dy, float deltaTime);
    void Fall(float deltaTime);
    void Jump(float deltaTime);

};