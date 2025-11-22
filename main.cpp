#include "raylib.h"
#include "player.h"
#include <vector>

//this is in preperation for ground tiles
std::vector<std::vector<int>> tiles ={
    {0,0,0},

};

int main(){
    InitWindow(0,0,"Raylib Test");
    ToggleFullscreen();
    SetTargetFPS(60);

    //gets the screen dimentions
    int screenW = GetScreenWidth();
    int screenH = GetScreenHeight();

    Player player(100.0f,200.0f);

    //load images
    Texture2D playerTexture = LoadTexture("assets/player.png");


    //while running
    while (!WindowShouldClose()){
        //get delta time every frame and resets velocity
        float deltaTime = GetFrameTime();
        Vector2 velocity = {0,0};

        //check for keypresses
        if (IsKeyDown(KEY_RIGHT)) velocity.x = 1.0f;
        if (IsKeyDown(KEY_LEFT)) velocity.x = -1.0f;

        player.Move(velocity.x,velocity.y, deltaTime);

        if (player.position.y < screenH-205){
            player.canJump = false;
            player.Fall(deltaTime);
        }else{
            player.acceleration = player.default_acceleration;
            player.canJump = true;

        }

        //draw what is on the screen
        BeginDrawing();
        ClearBackground(WHITE);
        
        //making a temporary ground rect
        DrawRectangle(0,screenH-100,screenW,100,GREEN);

        //draw the player
        DrawTextureEx(playerTexture,player.position,0.0f,player.size,WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}