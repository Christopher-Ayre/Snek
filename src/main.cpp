
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
        game.tick();
    }

    CloseWindow();        // Close window and OpenGL context


    return 0;
}