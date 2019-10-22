#pragma once
#include "Graphics.h"

#define DIRT                        0
#define GRASS                       1
#define BORDER_UP                   2
#define BORDER_DOWN                 3
#define BORDER_LEFT                 4
#define BORDER_RIGHT                5
#define BORDER_CORNER_TOPLEFT       6
#define BORDER_CORNER_TOPRIGHT      7
#define BORDER_CORNER_BOTTOMLEFT    8
#define BORDER_CORNER_BOTTOMRIGHT   9

class Map{
private:
    SDL_Renderer* renderer;
    SDL_Rect srcRect, destRect;
    SDL_Point center;
    SDL_Texture* grass;
    SDL_Texture* dirt;
    SDL_Texture* border;
    SDL_Texture* borderCorner;
    int map[20][25];
public:
    Map(SDL_Renderer* rendererName);
    ~Map();
    void loadMap(int inputMap[20][25]);
    void drawMap();
};