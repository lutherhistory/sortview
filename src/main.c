#include <raylib.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "visualizer.h"
#include "algorithm.h"


#define BG  (Color) { 0x18, 0x18, 0x18, 0xff }

#define WIDTH  800
#define HEIGHT 600
#define TITLE  "sortview -- just write something"


void draw_visualizer(Element *elm, Algorithm sorting_step)
{
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(20);

    Req   req   = { 0 };
    bool  broke = false;

    while (!WindowShouldClose())
    {
        if (sorting_step)
        {
            if (req.finished > 0)
                broke = is_sorted(elm);

            else
                sorting_step(elm, &req);
        }


        BeginDrawing();
        {
            ClearBackground(BG);

            Color tint = RAYWHITE;


            for (int i=0; i < (int) elm->count; i++)
            {
                if (req.finished > 0)
                {
                    tint = !broke ? GREEN : RAYWHITE;
                }
                else
                {
                    tint = req.disable && (req.x == i || req.y == i) ? RED : RAYWHITE;
                }


                Rectangle rec = {
                    .width  = WIDTH  / elm->count,
                    .height = HEIGHT / elm->count * elm->items[i] * 0.9f
                };
                rec.x = i * rec.width;
                rec.y = HEIGHT - rec.height;

                rec.width  *= 0.9f;


                DrawRectangleRec(rec, tint);
            }            
        }
        EndDrawing();
    }

    CloseWindow();
}

int main(void)
{
    const int N = 5;


    Element   elm = { 0 };
    Algorithm alg = bogo_sort;


    alloc_elm(&elm, N, shuffle_order);
    draw_visualizer(&elm, alg);

    free_elm(&elm);
    return 0;
}
