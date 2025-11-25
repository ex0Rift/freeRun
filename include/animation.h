#pragma once
#include "raylib.h"
#include <vector>

class Animation{
public:
    Texture2D currentFrame;
    std::vector<Texture2D> states;


    Animation(std::vector<Texture2D> states_import);
    void ChangeFrame(int change);
    
};
