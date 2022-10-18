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
    GameWorld(Snake& snake, int pixelSize, int screenMaxX, int screenMaxY);
    void tick();
private:
    void spawnNewApple();
    void handleCollisions();
    void draw();

    Snake& snake;
    Apple apple;
    int pixelSize;
    int screenMaxX;
    int screenMaxY;
    GameState gameState;
};
#endif