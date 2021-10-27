#ifndef SORT_H
#define SORT_H
#include <stdlib.h>

void Swap(char* string, int i, int j);

int Partition(char* string, int low, int high);

void Quicksort(char* string, int low, int high);

#endif