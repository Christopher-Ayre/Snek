#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "raylib.h"
#include "Apple.h"
#include "Snake.h"

enum GameState{
    PREGAME,
    PLAYING,
    GAMEOVER
};

class GameWorld{
    //class Snake;
public:
    GameWorld(Snake& snake, int pixelSize, Vector2 screenSize);
    void tick();
private:
    void handleCollisions();
    void draw();

    Snake& snake;
    Apple apple;
    int pixelSize;
    Vector2 screenSize;
    GameState gameState;
};
#endif