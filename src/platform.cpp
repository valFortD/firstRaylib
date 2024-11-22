#include "platform.hpp"

void Platform::Platforms()
{
    platforms[0] = (Rectangle){ 0, screen_height - 10, screen_width * 10, 10};      // Static platform

    // Create random platforms
    const float platform_width = screen_width * 0.3;
    const float platform_height = screen_height * 0.05;
    const int platform_min_y = screen_height * 0.4;
    const int platform_max_y = screen_height * 0.75;
    
    for(int i = 1; i < platform_count; i++) {
        float x = GetRandomValue(screen_width * 0.1, screen_width - 300);                     // Random x position
        float y = GetRandomValue(platform_min_y, platform_max_y);              // Random y position
        float width = platform_width;                                          // Platform width is 30% of screen width
        float height = platform_height;                                        // Platform height is 5% of screen height

        platforms[i] = (Rectangle){ x, y, width, height};
    }
}

void Platform::Draw()
{
    for(int i = 0; i < platform_count; i++) {
        DrawRectangle(platforms[i].x, platforms[i].y, platforms[i].width, platforms[i].height, BLACK);
    }
}