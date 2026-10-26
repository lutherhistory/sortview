#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

#include "algorithm.h"


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int is_sorted(Element *elm)
{
    for (size_t i=0, j=1; i < elm->count; i++, j++)
    {
        if (elm->items[i] < elm->items[j])
            return false;
    }

    return true;
}

void bubble_sort(Element *elm, Req *req)
{
    if (abs(req->finished) < elm->count)
    {
        // Swaps
        if (elm->items[req->x] > elm->items[req->y])
        {
            swap(&elm->items[req->x], &elm->items[req->y]);
            req->swaps++;
        }

        // Looping
        req->y = (req->y % (elm->count + req->finished)) + 1;
        if ((req->x = req->y - 1) == 0)
        {
            req->finished--;
        }
    }
    else
    {
        req->finished = elm->count;
    }
}

void selection_sort(Element *elm, Req *req)
{
    static int min_idx = 0;


    if (req->x < (int) elm->count - 1)
    {
        if (req->y % ((int) elm->count))
        {
            if (elm->items[min_idx] > elm->items[req->y])
                min_idx = req->y;

            req->y++;
        }
        else
        {
            if (req->x != req->y)
            {
                swap(&elm->items[min_idx], &elm->items[req->x]);
                min_idx = ++req->x;
            }

            req->y = req->x + 1;
        }
    }
    else
        req->finished = 1;
}

void quick_sort(Element *elm, Req *req)
{
    (void) elm, (void) req;

    // TODO: for 28.10.2026
    assert(false && "Not implement yet!");    
}

void merge_sort(Element *elm, Req *req)
{
    (void) elm, (void) req;

    // TODO: for 27.10.2026
    assert(false && "Not implement yet!");    
}

void insertion_sort(Element *elm, Req *req)
{
    (void) elm, (void) req;

    // TODO: for 26.10.2026
    assert(false && "Not implement yet!");
}
