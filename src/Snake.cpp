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
    move();

    //Draw all the body pieces 
    for(int ii=0; ii < body.size(); ii++)
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

    for(int ii=0; ii < body.size(); ii++)
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

void Snake::setDirection(Direction newDirection)
{
    direction = newDirection;
}

Direction Snake::getDirection()
{
    return direction;
}

const Vector2 Snake::getHead()
{
    return body[0];
}