#pragma once
#include "SDL2/SDL.h"

class ColliderComponent;

class Collision{
public:
    static bool AABBbox(const SDL_Rect &rectA, const SDL_Rect &rectB);
    static bool AABBbox(const ColliderComponent &colliderA, const ColliderComponent &colliderB);
};