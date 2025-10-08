#include <iostream>
#include <raylib.h>

int main(void)
{
    InitWindow(800, 800, "Sugi pula");
    
    Color cacat = (Color){79, 79, 79, 255};

    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(cacat);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}