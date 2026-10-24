#include <raylib.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>


#define BG  (Color) { 0x18, 0x18, 0x18, 0xff }

#define WIDTH  800
#define HEIGHT 600


typedef struct Element
{
    int   *items;
    size_t capc;
    size_t size;

    int  a;
    int  b;
} Element;

typedef void (*Algorithm)(Element*);


int left    = 0;
int swapped = 0;


void swap(int *a, int *b)
{
    int t  = *a;
    *a = *b;
    *b =  t;
}

void draw_items(Element *element)
{
    Color color = RAYWHITE;


    for (int i=0; i < element->size; i++)
    {
        Rectangle graph = {
            .width  = WIDTH  / element->size,
            .height = HEIGHT / element->size * element->items[i]
        };
        graph.x = i * graph.width;
        graph.y = HEIGHT - graph.height;

        float padding = graph.width - (graph.width * 0.9f);
        graph.x     += padding * 0.5f;
        graph.width -= padding;


        if (left < element->size)
        {
            color = (
                (i == element->a || i == element->b)
                ?
                RED
                :
                RAYWHITE
            );
        }
        else
        {
            color = LIME;
        }


        DrawRectangleRec(graph, color);
    }
}

void show_graph(Element *element, Algorithm algorithm)
{
    InitWindow(WIDTH, HEIGHT, "sortview -- yes yes welcome");
    SetTargetFPS(element->size);


    while (!WindowShouldClose())
    {
        algorithm(element);

        
        BeginDrawing();
        
        ClearBackground(BG);
        draw_items(element);

        DrawText(TextFormat("N: %d", element->size), 0, 0, 30, GREEN);
        DrawText(TextFormat("swapped: %d", swapped), 0, 30, 30, GREEN);
        
        EndDrawing();
    }

    CloseWindow();
}

void bubble_sort(Element *element)
{
    if (left < element->size) {
        if (element->items[element->a] > element->items[element->b])
        {
            swap(&element->items[element->a], &element->items[element->b]);
            swapped++;
        }
        
        element->b = element->b % (element->size - left) + 1;
        if (!(element->a = element->b - 1))
        {
            left++;
        }
    }
}

void insertion_sort(Element *element)
{
    (void) element;

    // TODO: insertion sort for tomorrow.
    assert(false && "Not implement yet!");
}

void selection_sort(Element *element)
{
    if (element->a < element->size-1)
    {
        if (element->items[element->a] > element->items[element->b])
        {
            swap(&element->items[element->a], &element->items[element->b]);
            swapped++;
        }


        if (element->b % (element->size - 1))
        {
            element->b++;
        }
        else
        {
            if (element->a != element->b)
                element->a++;
            
            element->b = element->a + 1;
        }
    }
    else
        left = element->size;
}

int main(void)
{
    Element   element;
    Algorithm algorithm = selection_sort;


    // Element's allocation
    element.capc  = 20;
    element.size  = 1;
    element.items = malloc(sizeof(*element.items) * element.size);

    element.a     = 0;
    element.b     = 0;


    for (size_t i=1; i <= element.capc; i++)
    {
        element.items      = realloc(element.items, sizeof(*element.items) * i);
        element.items[i-1] = i;
        element.size       = i;
    }

    // Element's value
    srand(time(0));
    for (int i=0; i < element.size; i++)
    {
        int j = rand() % (i+1);
        swap(&element.items[j], &element.items[i]);
    }
    for (int i=0; i < element.size; i++)
    {
        printf("%d, ", element.items[i]);
    }
    printf("\n");

    // Shows with graph
    show_graph(&element, algorithm);
    
    // Releasing the memory
    free(element.items);
    return 0;
}
