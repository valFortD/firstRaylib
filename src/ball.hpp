#pragma once
#include "platform.hpp"

class Ball {
public:
    int x, y;
    float size, speed_x, speed_y;

    void Draw();
    void Update(const Platform& platform);
    void CheckForCollision(const Platform& platform); // Referenced Platform

private:
    const float gravity = 0.25f;
};