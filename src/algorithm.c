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
    for (size_t i=1; i < elm->count; i++)
    {
        if (elm->items[i-1] > elm->items[i])
        {
            return true;
        }
    }

    return false;
}

void shuffle_order(Element *elm)
{
    srand(time(0));
    for (size_t i=0; i < elm->count; i++)
    {
        size_t j = (size_t) rand() % (i + 1);
        swap(&elm->items[i], &elm->items[j]);
    }
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
    if (req->y < elm->count)
    {
        if (req->x > 0 && elm->items[req->x-1] > elm->items[req->x])
        {
            swap(&elm->items[req->x-1], &elm->items[req->x]);

            if (req->x > 0)
                req->x--;
        }
        else
        {
            if (elm->items[req->x] > elm->items[req->y])
            {
                swap(&elm->items[req->x], &elm->items[req->y]);
            }
            else
            {
                req->y = (req->y % (elm->count)) + 1;
                req->x = req->y - 1;
            }
        }     
    }
    else
    {
        req->finished = true;
    }
}

void bogo_sort(Element *elm, Req *req)
{
    req->disable  = false;
    if (!(req->finished = !is_sorted(elm)))
    {
        shuffle_order(elm);
    }
}
