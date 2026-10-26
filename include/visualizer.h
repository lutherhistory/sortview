#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "struct.h"

// -- ( Memory Management ) --
void alloc_elm(Element *elm, const int N, void (*order)(Element*));

void free_elm(Element *elm);

// -- ( Some Helpers Functions ) -- 
void shuffle_order(Element *elm);

#endif //VISUALIZER_H
