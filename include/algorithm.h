#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <time.h>
#include <stdlib.h>
#include <stddef.h>

#include "struct.h"

// Algorithms
void bubble_sort(Element *elm, Req *req);

void selection_sort(Element *elm, Req *req);

void quick_sort(Element *elm, Req *req);

void merge_sort(Element *elm, Req *req);

void insertion_sort(Element *elm, Req *req);

void bogo_sort(Element *elm, Req *req);

// Helper Functions
void swap(int *a, int *b);

int is_sorted(Element *elm);

// -- ( Some Helpers Functions ) -- 
void shuffle_order(Element *elm);

#endif //ALGORITHM_H
