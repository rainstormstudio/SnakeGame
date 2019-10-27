#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL2/SDL.h"
#include <string>

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

class TileComponent : public Component{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    SDL_Rect tileRect;
    int tileID;
    std::string path;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id){
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;
    }

    void init() override{
        entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, 0, tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();

        switch(tileID){
        case DIRT:
            path = "assets/dirt.png";
            break;
        case GRASS:
            path = "assets/grass.png";
            break;
        case BORDER_UP:
            path = "assets/border.png";
            transform->angle = 0.0f;
            break;
        case BORDER_DOWN:
            path = "assets/border.png";
            transform->angle = 180.0f;
            break;
        case BORDER_LEFT:
            path = "assets/border.png";
            transform->angle = 270.0f;
            break;
        case BORDER_RIGHT:
            path = "assets/border.png";
            transform->angle = 90.0f;
            break;
        case BORDER_CORNER_TOPLEFT:
            path = "assets/border-corner.png";
            transform->angle = 0.0f;
            break;
        case BORDER_CORNER_TOPRIGHT:
            path = "assets/border-corner.png";
            transform->angle = 90.0f;
            break;
        case BORDER_CORNER_BOTTOMLEFT:
            path = "assets/border-corner.png";
            transform->angle = 270.0f;
            break;
        case BORDER_CORNER_BOTTOMRIGHT:
            path = "assets/border-corner.png";
            transform->angle = 180.0f;
            break;
        }

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};
