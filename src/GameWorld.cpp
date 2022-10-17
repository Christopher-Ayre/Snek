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

        break;

        case PLAYING:
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

}