#include "ball.hpp"
#include <raylib.h>

void Ball::Draw()
{
    DrawCircle(x, y, size, RED);
}

void Ball::Update(const Platform& platform)
{   
    // Player input
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) { x -= 4; }
    if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) { x += 4; }

    y += speedY;
    speedY += gravity;

    // Check for collision with platforms
    CheckForCollision(platform);
}

void Ball::CheckForCollision(const Platform &platform)
{
    for(int i = 0; i < Platform::platformCount; i++) {
        Rectangle platformRect = platform.platforms[i]; // Checking ball on current platform

        // Check collision
        if(CheckCollisionCircleRec(Vector2{x, y}, size, platformRect)) {
            // If collision detected, Rest ball position
            if(y + size > platformRect.y && y < platformRect.y + platformRect.height) {
                // Ball on platform
                y = platformRect.y - size; // Place ball on top of platform
                    speedY = 0;
            } else {
                speedY = -speedY + 10; // Bounce the ball downwards if it hits the platform's bottom
                // -speedY to change it's direction downwards
            }

            if(IsKeyPressed(KEY_SPACE)) { speedY = -23; }
        }
    }
}
