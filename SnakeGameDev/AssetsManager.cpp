#include "AssetsManager.h"
#include "ECS/Components.h"

AssetManager::AssetManager(Manager* mng) : manager(mng){}

AssetManager::~AssetManager(){}

void AssetManager::createProjectile(Vector2D position, Vector2D velocity, int range, double speed, std::string id){
    auto& projectile(manager->addEntity());
    projectile.addComponent<TransformComponent>(position.x, position.y, speed, 32, 32, 1);
    projectile.addComponent<SpriteComponent>(id, false);
    projectile.addComponent<ProjectileComponent>(range, speed, velocity);
    projectile.addComponent<ColliderComponent>("projectile");
    projectile.addGroup(Game::groupProjectiles);
    printf("projectile created\n");
}

void AssetManager::addTexture(std::string id, std::string path){
    textures.emplace(id, Graphics::loadTexture(path));
}

SDL_Texture* AssetManager::getTexture(std::string id){
    return textures[id];
}
