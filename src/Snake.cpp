#include "Snake.h"
#include <iostream>

Snake::Snake(Vector2 head, float size)
{
    body.push_back(head);
    bodyPieceSize = size;
    direction = Direction::RIGHT;
}

void Snake::draw()
{
    //Draw all the body pieces 
    for(size_t ii=0; ii < body.size(); ii++)
    {
        DrawRectangleV(body[ii], {bodyPieceSize, bodyPieceSize}, RED);
    }
}

void Snake::move()
{
    Vector2 nextPos; // The direction we are moving too.
    Vector2 temp;
    switch (direction)
    {
    case Direction::UP:
        nextPos = {body[0].x, body[0].y - bodyPieceSize};
        break;

    case Direction::DOWN:
        nextPos = {body[0].x, body[0].y + bodyPieceSize};
        break;

    case Direction::LEFT:
        nextPos = {body[0].x - bodyPieceSize, body[0].y};
        break;

    case Direction::RIGHT:
        nextPos = {body[0].x + bodyPieceSize, body[0].y};
        break;
    }

    for(size_t ii=0; ii < body.size(); ii++)
    {
        temp = body[ii];
        body[ii] = nextPos;
        nextPos = temp;
    }
}

void Snake::addLength()
{
    float xPos = 0;
    float yPos = 0;
    switch(direction)
    {
        case Direction::UP:
            yPos = body.back().y + bodyPieceSize;
            xPos = body.back().x;
            break;

        case Direction::DOWN:
            yPos = body.back().y - bodyPieceSize;
            xPos = body.back().x;
            break;

        case Direction::LEFT:
            yPos = body.back().y;
            xPos = body.back().x + bodyPieceSize;
            break;

        case Direction::RIGHT:
            yPos = body.back().y;
            xPos = body.back().x - bodyPieceSize;
            break;
    }
    body.push_back({xPos,yPos});
}

bool Snake::hasLoopedOnSelf()
{
    bool loop = false;
    Vector2 head = getHead();

    //Start at 1 so we dont check the head position against the head position
    for (size_t ii = 1; ii < body.size(); ii++)
    {
        //If the head is in the same place as a body piece then we have collided 
        if(head.x == body[ii].x && head.y == body[ii].y)
        {
            loop = true;
        }
    }
    
    return loop;
}

Direction Snake::getDirection()
{
    return direction;
}

void Snake::setDirection(Direction newDirection)
{
    direction = newDirection;
}

const Vector2 Snake::getHead()
{
    return body[0];
}