
#include "raylib.h"
#include "Snake.h"
#include "Apple.h"
#include "GameWorld.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Snek");

    Snake snek({20,20}, 20);
    snek.setDirection(Direction::RIGHT);
    snek.addLength();
    snek.addLength();
    snek.addLength();
    snek.addLength();
    snek.addLength();
    snek.addLength();
    snek.addLength();
    snek.addLength();
    snek.addLength();

    GameWorld game(snek,20,{screenWidth, screenHeight});

    SetTargetFPS(8);               // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //We have to check for current direction because we dont allow the snake to turn back on itself
        if ((IsKeyDown(KEY_D) || IsKeyReleased(KEY_D)) && snek.getDirection() != Direction::LEFT) snek.setDirection(Direction::RIGHT);
        if ((IsKeyDown(KEY_A) || IsKeyReleased(KEY_A)) && snek.getDirection() != Direction::RIGHT) snek.setDirection(Direction::LEFT);
        if ((IsKeyDown(KEY_W) || IsKeyReleased(KEY_W)) && snek.getDirection() != Direction::DOWN) snek.setDirection(Direction::UP);
        if ((IsKeyDown(KEY_S) || IsKeyReleased(KEY_S)) && snek.getDirection() != Direction::UP) snek.setDirection(Direction::DOWN);

        game.tick();
    }

    CloseWindow();        // Close window and OpenGL context


    return 0;
}