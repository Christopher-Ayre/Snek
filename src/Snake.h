#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include <vector>

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

class Snake{
public:
    Snake(Vector2 head, float size);
    void draw();
    const Vector2 getHead();
    void setDirection(Direction direction);
    bool hasLoopedOnSelf();
    Direction getDirection();
    void addLength();
    void move();
private:
    std::vector<Vector2> body;
    float bodyPieceSize;
    Direction direction;
};

#endif