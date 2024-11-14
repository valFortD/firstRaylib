#pragma once
#include "platform.hpp"

class Ball {
public:
    float x, y, size, speedX, speedY;

    void Draw();
    void Update(const Platform& platform);
    void CheckForCollision(const Platform& platform); // Reference

private:
    const float gravity = 0.5f;
};