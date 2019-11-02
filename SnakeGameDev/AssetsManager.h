#pragma once
#include <map>
#include <string>
#include "Graphics.h"
#include "Vector2D.h"
#include "ECS/ECS.h"

class AssetManager{
private:
    Manager *manager;
    std::map<std::string, SDL_Texture*> textures;
public:
    AssetManager(Manager* mng);
    ~AssetManager();

    // game objects
    void createProjectile(Vector2D position, int range, int speed, std::string id);

    // texture management
    void addTexture(std::string id, std::string path);
    SDL_Texture* getTexture(std::string id);
};