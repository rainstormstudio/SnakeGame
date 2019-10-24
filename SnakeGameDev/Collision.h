#pragma once
#include "SDL2/SDL.h"

class Collision{
public:
    static bool AABBbox(const SDL_Rect &rectA, const SDL_Rect &rectB);
};