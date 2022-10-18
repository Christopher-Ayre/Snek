#include "GameWorld.h"
#include "Snake.h"
#include "Apple.h"

#include <random>
#include <iostream>

GameWorld::GameWorld(Snake& snake, int pixelSize, int screenMaxX, int screenMaxY) : 
    snake(snake),
    apple({200,200}),
    pixelSize(pixelSize),
    screenMaxX(screenMaxX),
    screenMaxY(screenMaxY),
    gameState(PREGAME)
    {} 

void GameWorld::tick()
{
    if(gameState == PLAYING)
    {
        //We have to check for current direction because we dont allow the snake to turn back on itself
        if (IsKeyDown(KEY_D) && snake.getDirection() != Direction::LEFT) { snake.setDirection(Direction::RIGHT); }
        if (IsKeyDown(KEY_A) && snake.getDirection() != Direction::RIGHT) { snake.setDirection(Direction::LEFT); }
        if (IsKeyDown(KEY_W) && snake.getDirection() != Direction::DOWN) { snake.setDirection(Direction::UP); }
        if (IsKeyDown(KEY_S) && snake.getDirection() != Direction::UP) { snake.setDirection(Direction::DOWN); }

        if(apple.isAt(snake.getHead()))
        {
            spawnNewApple();
            snake.addLength();
        }

        snake.move();
    }

    draw();
}

void GameWorld::draw()
{
    BeginDrawing();

    switch(gameState)
    { 
        case PREGAME:
            ClearBackground(WHITE);
            DrawText("SNEK", screenMaxX/5, screenMaxY/5, 60, BLACK);
            DrawText("Press space to play", screenMaxX/3, screenMaxY/3, 30, DARKGRAY);

            if (IsKeyDown(KEY_SPACE)){ gameState = PLAYING; }
        break;

        case GAMEOVER:
            ClearBackground(BLACK);
            DrawText("GAME OVER", screenMaxX/5, screenMaxY/5, 60, WHITE);
        break;

        case PLAYING:
            handleCollisions();
            snake.draw();
            apple.draw();
            ClearBackground(DARKGRAY);
            DrawText("Move the snake with WASD keys", 10, 10, 20, BLACK);
        break;
    }

    EndDrawing();
}

void GameWorld::handleCollisions()
{
    Vector2 snakeHead = snake.getHead();
    bool ofScreenX = (snakeHead.x <= 0 || snakeHead.x >= screenMaxX);
    bool ofScreenY = (snakeHead.y <= 0 || snakeHead.y >= screenMaxY);

    if(snake.hasLoopedOnSelf() || ofScreenX || ofScreenY )
    {
        gameState = GAMEOVER;
    }
}

void GameWorld::spawnNewApple()
{
    int newX = rand() % screenMaxX + 1;
    int newY = rand() % screenMaxY + 1;

    //This needs to take into account the pixel size so that the snake lines up with it.
    newX = (newX/pixelSize) * pixelSize;
    newY = (newY/pixelSize) * pixelSize;

    std::cout << newX << " : " << newY << std::endl;
    apple = Apple({newX,newY});
}