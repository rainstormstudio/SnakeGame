#include "Collision.h"
#include "ECS/ColliderComponent.h"

bool Collision::AABBbox(const SDL_Rect &rectA, const SDL_Rect &rectB){
    bool collided = false;
    if (rectA.x + rectA.w >= rectB.x &&
        rectB.x + rectB.w >= rectA.x &&
        rectA.y + rectA.h >= rectB.y &&
        rectB.y + rectB.h >= rectA.y
        ){
            collided = true;
    }
    return collided;
}


bool Collision::AABBbox(const ColliderComponent &colliderA, const ColliderComponent &colliderB){
    bool collided = false;
    if (AABBbox(colliderA.collider, colliderB.collider)){
        std::cout << colliderA.tag << " hit: " << colliderB.tag << std::endl;
        collided = true;
    }
    return collided;
}