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

    Camera2D camera = {0};
    camera.target = (Vector2){ball.x, ball.y};                  // Follows the ball
    camera.offset = (Vector2) {screenWidth/2, screenHeight/2};  // The camera centered on the screen
    camera.zoom = 1.0f;

    while(!WindowShouldClose()) {
        // Update
        ball.Update(platform);

        // Update camera target
        if(ball.x > screenWidth * 0.8) {
            camera.offset.x = -(ball.x - screenWidth/2);
        }
        if(camera.offset.x < 0) {
            camera.offset.x = 0; // Prevent the ball from going past left
        }

        BeginDrawing();
        ClearBackground(lightGreen);

        BeginMode2D(camera);

        // Draw
        platform.Draw();
        ball.Draw();

        EndMode2D();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}