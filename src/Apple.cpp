#include "Apple.h"

Apple::Apple(Vector2 position) : position(position)
{
}

void Apple::draw()
{
    DrawRectangleV(position, {20, 20}, WHITE);
}