#include "Apple.h"

Apple::Apple(Vector2 position) : position(position)
{
}

void Apple::draw()
{
    DrawRectangleV(position, {20, 20}, WHITE);
}

bool Apple::isAt(Vector2 targetPos)
{
    if(targetPos.x == position.x && targetPos.y == position.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}