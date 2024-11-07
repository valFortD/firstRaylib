#pragma once
#include <raylib.h>

class Platform {
public:
    float x, y, width, height;
    const float screenWidth = 800;
    const float screenHeight = 600;
    static const int platformCount = 3; // 1 static and 2 random platforms
    Rectangle platforms[platformCount];

    void makePlatforms();
    void Draw();
};