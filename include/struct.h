#ifndef STRUCT_H
#define STRUCT_H

typedef struct
{
    int x;
    int y;

    // boolean types
    int finished;
    int swapped;
    int disable; // NOTE: disable the indicators.

    // helpers.
    int swaps; 
    int ms;       // NOTE: duration of actual sorted time.
} Req;

typedef struct
{
    int *items;
    size_t count;
    size_t capacity;
} Element;

typedef void (*Algorithm)(Element*, Req*);

#endif //STRUCT_H
