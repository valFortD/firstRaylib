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
        Rectangle platformRect = platform.platforms[i];
        Rectangle ballRect = {
            .x = x- size,
            .y = y - size,
            .width = size * 2,
            .height = size * 2
        };

        // Check collision
        if(CheckCollisionRecs(ballRect, platformRect)) {
            if(y + size > platformRect.y && y < platformRect.y + platformRect.height) {
                y = platformRect.y - size; // Place ball on top of platform
                speedY = 0;                // Stop ball once on platform

            if(IsKeyPressed(KEY_SPACE)) { speedY = -17; }

            } else {
                speedY = -speedY + 5; // Reverse ball direction if it hits the platform's bottom
                // -speedY to change it's direction downwards
            }
        }
    }
}