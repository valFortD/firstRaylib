#include <raylib.h>
#include "platform.hpp"
#include "ball.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const Color lightGreen = {222, 250, 222, 255};
    
    InitWindow(screenWidth, screenHeight, "First Raylib game");
    SetTargetFPS(60);

    // Initialize
    Platform platform;
    platform.makePlatforms();

    Ball ball;
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    ball.size = 28;
    ball.gravity = 1;

    while(!WindowShouldClose()) {
        // Update
        ball.Update(platform);

        BeginDrawing();
        ClearBackground(lightGreen);

        // Draw
        platform.Draw();
        ball.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}