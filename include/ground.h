#pragma once
#include "raylib.h"
#include <vector>

struct Result {
    bool hit;
    float x;
    float y;
};

class Ground{
public:
    Texture2D dirtTile;
    Texture2D grassTile;
    float groundScale;
    Vector2 position;
    std::vector<std::vector<int>> groundTiles;

    Ground();
    void Draw();
    void Move(float x = 0.0f, float y = 0.0f);
    Result Collide(float px, float py);
};