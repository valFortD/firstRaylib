#pragma once
#include "platform.hpp"

class Ball {
public:
    float x, y;
    int size;
    float speedX;
    float speedY;
    float gravity;

    void Draw();
    void Update(const Platform& platform);
    void CheckForCollision(const Platform& platform); // Reference
};