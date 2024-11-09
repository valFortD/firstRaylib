#pragma once
#include "platform.hpp"

class Ball {
public:
    float x, y;
    float size;
    float speedX;
    float speedY;
    float gravity;

    void Draw();
    void Update(const Platform& platform);
    void CheckForCollision(const Platform& platform); // Reference
};