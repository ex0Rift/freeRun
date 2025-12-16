#pragma once
#include "raylib.h"
#include <vector>
#include <random>

struct Result {
    bool hit;
    int x;
    int y;
};

class Ground{
public:
    Texture2D dirtTile;
    Texture2D grassTile;
    float groundScale;
    int chunkDistance;
    Vector2 position;
    std::vector<std::vector<int>> groundTiles;
    std::vector<std::vector<std::vector<int>>> chunksInUse;
    std::random_device seed;

    Ground();
    void Draw();
    Result Collide(float px, float py, float chunkX);
    void genChunk(int direction,bool startMode = false);
};