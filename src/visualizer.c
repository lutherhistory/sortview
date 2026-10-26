#include "visualizer.h"
#include "algorithm.h"

void alloc_elm(Element *elm, const int N, void (*order)(Element*))
{
    for (int i=0; i < N; i++)
    {
        if (elm->count >= elm->capacity)
        {
            if (elm->capacity == 0) elm->capacity = 2 * N;
            else elm->capacity *= 2;


            void* tmp;
            if ((tmp = realloc(elm->items, elm->capacity * sizeof(*elm->items))))
            {
                elm->items = tmp;
            }
            else
            {
                free(elm->items);

                perror("elm->items");
                exit(1);
            }
        }

        elm->items[elm->count++] = i + 1;
    }

    if (order) order(elm);
}

void free_elm(Element *elm)
{
    free(elm->items);
}
