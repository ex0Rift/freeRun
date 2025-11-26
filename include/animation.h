#pragma once
#include "raylib.h"
#include <vector>

class Animation{
private:
    int currentSpeedTime;
    int currentFrameInUse;

public:
    Texture2D currentFrame;
    std::vector<Texture2D> states;
    std:: vector<int> useFrames;
    bool active;
    int speed;

    Animation(std::vector<Texture2D> states_import);
    void ChangeFrame(int change);
    void InitAnimate(std::vector<int> changeframes, float speed);
    void Disable();
    void Animate();

};
