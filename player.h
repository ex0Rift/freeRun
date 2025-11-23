#pragma once
#include "raylib.h"

class Player{
public:
    Vector2 position;
    float speed;
    float jumpHeight;
    int size;
    float acceleration;
    float default_acceleration;
    bool inair;
    

    Player(float x, float y);
    void Move(float dx, float dy, float deltaTime);
    void Fall(float deltaTime);
    void Jump(float deltaTime);

};