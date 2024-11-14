#pragma once
#include <raylib.h>

class Platform {
public:
    float x, y, width, height;
    const float screen_width = 800;
    const float screen_height = 600;
    static const int platform_count = 3; // 1 static and 2 random platforms
    Rectangle platforms[platform_count];

    void makePlatforms();
    void Draw();
};