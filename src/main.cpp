#include "raylib.h"
#include "player.h"
#include "ground.h"
#include <vector>
#include <cstdio>

int main(){
    InitWindow(0,0,"Raylib Test");
    ToggleFullscreen();
    SetTargetFPS(60);

    //gets the screen dimentions
    int screenW = GetScreenWidth();
    int screenH = GetScreenHeight();

    Player player(100.0f,200.0f);

    Ground ground;

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
        if (IsKeyDown(KEY_UP)) player.acceleration = -500.0f;
       

        player.Move(velocity.x,velocity.y, deltaTime);

        if (player.position.y <= screenH-200){
            player.inair = true;
        }else{
            player.inair = false;
            player.position.y = screenH - 200;
            player.acceleration = 0;
        }
        player.Fall(deltaTime);

        //draw what is on the screen
        BeginDrawing();
        ClearBackground(WHITE);

        //draw all the ground
        ground.Draw();
        
        //making a temporary ground rect
        DrawRectangle(0,screenH-100,screenW,100,GREEN);

        //draw the player
        DrawTextureEx(playerTexture,player.position,0.0f,player.size,WHITE);


        //debug UI
        char debug_onground[30];
        snprintf(debug_onground, sizeof(debug_onground), "inAir: %s", player.inair ? "true": "false");
        DrawText(debug_onground, 10 , 10 ,40 , BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}