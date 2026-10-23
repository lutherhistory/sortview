#include <raylib.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define WIDTH  900
#define HEIGHT 600

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void update(bool (*algorithm)(int *items, int count), int *items, int count, float dt)
{
    (void) dt;
    
    if (algorithm(items, count))
    {
        TraceLog(LOG_INFO, "Done!");
    }
}

bool bubble_sort(int *items, int count)
{
    static int i = 0, j = 1, n = 0;
    if (n == 0)
        n = count;

    if (items[i] > items[j])
    {
        swap(&items[i], &items[j]);
    }
    else
    {
        
    }
    j = j % (n - 1) + 1, i = j - 1;

    
    return false;
}

int main(void)
{
    int count  = 10;
    int *items = (int*)calloc((size_t)count, sizeof(int));
    
    if (!items)
    {
        perror("calloc");
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    for (int i=0; i < count; i++)
    {
        items[i] = i + 1;
    }
    // shuffle
    for (int i=0; i < count; i++)
    {
        int j = rand() % (1 + i);
        
        swap(&items[i], &items[j]);
    }
    
    
    InitWindow(WIDTH, HEIGHT, "sortview");
    SetTargetFPS(60);

    bool (*algorithm)(int *items, int count) = &bubble_sort;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        update(algorithm, items, count, dt);
        
        
        BeginDrawing();

        ClearBackground(BLACK);

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

            size.x *= 0.8;
            
            DrawRectangleV(pos, size, RAYWHITE);
        }

        EndDrawing();
    }

    free(items);

    CloseWindow();
    return 0;
}
