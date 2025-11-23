#include "ground.h"
#include "raylib.h"

Ground::Ground(){
    dirtTile = LoadTexture("assets/ground/dirt.png");
    groundScale = 4;
    
    groundTiles.assign({
        {1,1},
        {1,0}
    });

}

void Ground::Draw(){
    for (size_t i = 0; i < groundTiles.size(); i++){
        for (size_t j = 0; j < groundTiles[i].size(); j++){
            if (groundTiles[i][j] != 0){
                //convert loop index into floats
                float fi = static_cast<float>(i);
                float fj = static_cast<float>(j);

                DrawTextureEx(dirtTile,{fi*(32*groundScale),fj*(32*groundScale)},0.0f,groundScale,WHITE);
            }
        }
    }
}