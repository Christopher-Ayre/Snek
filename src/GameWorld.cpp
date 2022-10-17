#include "GameWorld.h"
#include "Snake.h"
#include "Apple.h"

GameWorld::GameWorld(Snake& snake, int pixelSize, Vector2 screenSize) : 
    snake(snake),
    apple({20,20}),
    pixelSize(pixelSize),
    screenSize(screenSize),
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
            DrawText("SNEK", screenSize.x/5, screenSize.y/5, 60, BLACK);
            DrawText("Press space to play", screenSize.x/3, screenSize.y/3, 30, DARKGRAY);

            if (IsKeyDown(KEY_SPACE)){ gameState = PLAYING; }
        break;

        case GAMEOVER:
            ClearBackground(BLACK);
            DrawText("GAME OVER", screenSize.x/5, screenSize.y/5, 60, WHITE);
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
    if(snake.hasLoopedOnSelf())
    {
        gameState = GAMEOVER;
    }
}