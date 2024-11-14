#pragma once
#include "platform.hpp"

void Platform::makePlatforms()
{
    platforms[0] = (Rectangle){ 0, screenHeight - 10, screenWidth * 10, 10};     // Static platform

    // Create random platforms
    int platformMin_y = screenHeight * 0.4;
    int platformMax_y = screenHeight * 0.75;
    for(int i = 1; i < platformCount; i++) {
        float x = GetRandomValue(300, screenWidth * 0.1);                  // Random x position
        float y = GetRandomValue(platformMin_y, platformMax_y);            // Random y position
        float width = screenWidth * 0.3;                                   // Platform width is 30% of screen width
        float height = screenHeight * 0.05;                                // Platform height is 5% of screen height

        platforms[i] = (Rectangle){ x, y, width, height};
    }
}

void Platform::Draw()
{
    for(int i = 0; i < platformCount; i++) {
        DrawRectangle(platforms[i].x, platforms[i].y, platforms[i].width, platforms[i].height, BLACK);
    }
}