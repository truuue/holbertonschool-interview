#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT  0
#define SLIDE_RIGHT 1

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int slide_line(int *line, size_t size, int direction);

#endif