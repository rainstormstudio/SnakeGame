#pragma once
#include "Graphics.h"
#include <string>

class Map{
private:
    std::string mapFilePath;
    int mapScale;
    int tileSize;
    int scaledSize;
public:
    Map(std::string mfp, int ms, int ts);
    ~Map();
    void loadMap(std::string path, int sizeX, int sizeY);
    void addTile(int srcX, int srcY, int posX, int posY, int theta);
    void drawMap();
};