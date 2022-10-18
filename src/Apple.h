#ifndef APPLE_H
#define APPLE_H

#include "raylib.h"

class Apple
{
public:
    Apple(Vector2 position);
    bool isAt(Vector2 position);
    void draw();
private:
    Vector2 position;
};

#endif