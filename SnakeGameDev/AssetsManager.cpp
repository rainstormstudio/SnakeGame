#include "AssetsManager.h"

AssetManager::AssetManager(Manager* mng) : manager(mng){

}

AssetManager::~AssetManager(){}

void AssetManager::addTexture(std::string id, std::string path){
    textures.emplace(id, Graphics::loadTexture(path));
}

SDL_Texture* AssetManager::getTexture(std::string id){
    return textures[id];
}