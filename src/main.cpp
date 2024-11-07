#include <raylib.h>
#include "platform.hpp"
#include "ball.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const Color nyanza = {233, 255, 219, 250};
    
    InitWindow(screenWidth, screenHeight, "First Raylib game");
    SetTargetFPS(60);

    // Initialize
    Platform platform;
    platform.makePlatforms();

    Ball ball;
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    ball.size = 26;
    ball.gravity = 1;

    while(!WindowShouldClose()) {
        // Update
        ball.Update(platform);

        BeginDrawing();
        ClearBackground(nyanza);

        // Draw
        platform.Draw();
        ball.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}