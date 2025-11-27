#include "raylib.h"
#include "animation.h"

Animation::Animation(std::vector<Texture2D> states_import){
    states = states_import;
    currentFrame = states[0];
    active = false;
    speed = 10;
    currentSpeedTime = speed;
    currentFrameInUse = 0;
}

void Animation::ChangeFrame(int change){
    currentFrame = states[change];
}

void Animation::InitAnimate(std::vector<int> changeframes, float changeSpeed){
    speed = changeSpeed;
    //currentSpeedTime = speed;
    //currentFrameInUse = 0;
    useFrames = changeframes; 
    active = true;
}

void Animation::Disable(){active = false;}

void Animation::Animate(){
    if (active){
        if (currentSpeedTime == 0){
            if (currentFrameInUse == useFrames.size()-1){
                currentFrameInUse = 0;
            }else currentFrameInUse ++;

            currentFrame = states[useFrames[currentFrameInUse]];
            
            currentSpeedTime = speed;
        }else currentSpeedTime -= 1;
        
    }
}