#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <stddef.h>
#include <stdio.h>

#include "struct.h"

// -- ( Memory Management ) --
void alloc_elm(Element *elm, const int N, void (*order)(Element*));

void free_elm(Element *elm);

#endif //VISUALIZER_H
