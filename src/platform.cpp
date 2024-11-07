#include "platform.hpp"

void Platform::makePlatforms()
{
    platforms[0] = (Rectangle){ 0, screenHeight - 20, screenWidth, 25}; // Static platform

    // Create random platforms
    for(int i = 1; i < platformCount; i++) {
        float width = 200;
        float height = 25;
        float x = GetRandomValue(300, GetScreenWidth() - width); // Random x position
        float y = GetRandomValue(300, screenHeight - 150); // Random y position

        platforms[i] = (Rectangle){ x, y, width, height};
    }
}

void Platform::Draw()
{
    for(int i = 0; i < platformCount; i++) {
        DrawRectangle(platforms[i].x, platforms[i].y, platforms[i].width, platforms[i].height, BLACK);
    }
}