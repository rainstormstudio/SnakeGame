#include "Map.h"

int lvl1[20][25] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 9, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

Map::Map(SDL_Renderer* rendererName){
    renderer = rendererName;

    dirt = Graphics::loadTexture("assets/dirt.png", renderer);
    grass = Graphics::loadTexture("assets/grass.png", renderer);
    border = Graphics::loadTexture("assets/border.png", renderer);
    borderCorner = Graphics::loadTexture("assets/border-corner.png", renderer);

    loadMap(lvl1);
    srcRect.x = srcRect.y = 0;
    srcRect.h = srcRect.w = 32;
    center.x = center.y = 32 / 2;
    destRect.x = destRect.y = 0;
    destRect.w = destRect.h = 32;
}

Map::~Map(){
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(border);
    SDL_DestroyTexture(borderCorner);
}

void Map::loadMap(int inputMap[20][25]){
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 25; j++){
            map[i][j] = inputMap[i][j];
        }
    }
}

void Map::drawMap(){
    int type = 0;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 25; j++){
            destRect.x = 32 * j;
            destRect.y = 32 * i;
            type = map[i][j];
            switch (type){
                case DIRT: Graphics::drawTexture(dirt, srcRect, destRect, 0, center, SDL_FLIP_NONE, renderer); break;
                case GRASS: Graphics::drawTexture(grass, srcRect, destRect, 0, center, SDL_FLIP_NONE, renderer); break;
                case BORDER_UP: Graphics::drawTexture(border, srcRect, destRect, 0, center, SDL_FLIP_NONE, renderer); break;
                case BORDER_DOWN: Graphics::drawTexture(border, srcRect, destRect, 180, center, SDL_FLIP_NONE, renderer); break;
                case BORDER_LEFT: Graphics::drawTexture(border, srcRect, destRect, 270, center, SDL_FLIP_NONE, renderer); break;
                case BORDER_RIGHT: Graphics::drawTexture(border, srcRect, destRect, 90, center, SDL_FLIP_NONE, renderer); break;
                case BORDER_CORNER_TOPLEFT: Graphics::drawTexture(borderCorner, srcRect, destRect, 0, center, SDL_FLIP_NONE, renderer); break;
                case BORDER_CORNER_TOPRIGHT: Graphics::drawTexture(borderCorner, srcRect, destRect, 90, center, SDL_FLIP_NONE, renderer); break;
                case BORDER_CORNER_BOTTOMLEFT: Graphics::drawTexture(borderCorner, srcRect, destRect, 270, center, SDL_FLIP_NONE, renderer); break;
                case BORDER_CORNER_BOTTOMRIGHT: Graphics::drawTexture(borderCorner, srcRect, destRect, 180, center, SDL_FLIP_NONE, renderer); break;
            }
        }
    }
}
