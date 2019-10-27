#pragma once
#include "Graphics.h"
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

class Map{
private:
public:
    Map();
    ~Map();
    static void loadMap(std::string path, int sizeX, int sizeY);
    void drawMap();
};