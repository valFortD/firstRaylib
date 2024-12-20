#include <raylib.h>
#include "platform.hpp"
#include "ball.hpp"

int main() {
    const int screen_width = 800;
    const int screen_height = 600;
    const Color light_green = {222, 250, 222, 255};
    
    InitWindow(screen_width, screen_height, "First Raylib game");
    SetTargetFPS(60);

    // Initialize
    Platform platform;
    platform.Platforms();

    Ball ball;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.size = 30;

    Camera2D camera = {0};
    camera.target = (Vector2){(float)ball.x, (float)ball.y};
    camera.offset = (Vector2) {screen_width/2, screen_height/2};  // The camera centered on the screen
    camera.zoom = 1.0f;

    while(!WindowShouldClose()) {                                 // Game loop
        // Update
        ball.Update(platform);

        if(ball.x > screen_width * 0.8) {                        // Update camera target
            camera.offset.x = -(ball.x - screen_width/2);
        }
        if(camera.offset.x < 0) {
            camera.offset.x = 0;                                 // Prevent the ball from going past left
        }

        BeginDrawing();
        ClearBackground(light_green);

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