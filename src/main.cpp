
#include "raylib.h"
#include "IRenderable.h"
#include "Snake.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Snek");

    Snake snek({20,20}, 20);
    snek.setDirection(Direction::LEFT);
    snek.addLength();
    snek.addLength();
    snek.addLength();

    SetTargetFPS(10);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //We have to check for current direction because we dont allow the snake to turn back on itself
        if (IsKeyDown(KEY_D) & snek.getDirection() != Direction::LEFT) snek.setDirection(Direction::RIGHT);
        if (IsKeyDown(KEY_A) & snek.getDirection() != Direction::RIGHT) snek.setDirection(Direction::LEFT);
        if (IsKeyDown(KEY_W) & snek.getDirection() != Direction::DOWN) snek.setDirection(Direction::UP);
        if (IsKeyDown(KEY_S) & snek.getDirection() != Direction::UP) snek.setDirection(Direction::DOWN);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            snek.draw();
            

            ClearBackground(BLACK);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}