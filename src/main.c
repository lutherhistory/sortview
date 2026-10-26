#include <raylib.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "visualizer.h"


#define BG  (Color) { 0x18, 0x18, 0x18, 0xff }

#define WIDTH  800
#define HEIGHT 600
#define TITLE  "sortview -- just write something"


const int N = 20;


void draw_visualizer(Element *elm, void*)
{
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(BG);
            for (size_t i=0; i < elm->count; i++)
            {
                Rectangle rec = {
                    .width  = WIDTH  / elm->count,
                    .height = HEIGHT / elm->count * elm->items[i] * 0.9f
                };
                rec.x = i * rec.width;
                rec.y = HEIGHT - rec.height;

                rec.width  *= 0.9f;


                DrawRectangleRec(rec, RAYWHITE);
            }            
        }
        EndDrawing();
    }

    CloseWindow();
}

int main(void)
{
    Element elm = { 0 };
    alloc_elm(&elm, N, shuffle_order);


    draw_visualizer(&elm, NULL);


    free_elm(&elm);
    return 0;
}
