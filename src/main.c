#include <raylib.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define BG  (Color) { 0x18, 0x18, 0x18, 0xff }

#define WIDTH  800
#define HEIGHT 600


typedef bool (*Algorithm)(int*, size_t);

static int a = 0;
static int b = 0;


void swap(int *a, int *b)
{
    int t;

     t  = *a;
     *a = *b;
     *b =  t;
}

int *create_items(size_t count)
{
    int *items = malloc(sizeof(int) * count);

    for (size_t i=0; i < count; i++)
    {
        items[i] = i + 1;
    }

    return items;
}

void shuffle_items(int *items, size_t count)
{
    srand(time(0));
    for (int i=0; i < count; i++)
    {
        int j = rand() % (i+1);
        swap(&items[i], &items[j]);
    }
}

void update_sorting(Algorithm algorithm, int *items, size_t count)
{
    if (algorithm(items, count))
    {
        TraceLog(LOG_INFO, "Done!");
    }
}

bool bubble_sort(int *items, size_t count)
{
    if (items[a] > items[b])
    {
        swap(&items[a], &items[b]);
    }

    b = b % count + 1, a = b - 1;

    return false;
}

int main(int argc, char **argv)
{
    size_t count = 10;
    int   *items = create_items(count);
    Algorithm algorithm = bubble_sort;


    if (!items)
    {
        fprintf(stderr, "%s: empty array\n", argv[0]);
        return EXIT_FAILURE;
    }

    shuffle_items(items, count);
    

    InitWindow(WIDTH, HEIGHT, "sortview -- recreational project");
    SetTargetFPS(count);

    while (!WindowShouldClose())
    {
        update_sorting(algorithm, items, count);
        

        BeginDrawing();
        
        ClearBackground(BG);
        for (int i=0; i < count; i++)
        {
            Vector2 size = {
                WIDTH  / count,
                HEIGHT / count * items[i]
            };

            Vector2 pos  = {
                i * size.x,
                HEIGHT - size.y
            };

            Color color = RAYWHITE;
            if (a == i || b == i)
            {
                color = RED;
            }

            size.x *= 0.9f;
            
            
            DrawRectangleV(pos, size, color);
        }
        
        EndDrawing();
    }

    free(items);
    CloseWindow();
    return 0;
}
