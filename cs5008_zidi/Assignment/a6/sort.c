#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void Swap(char* string, int i, int j) {
  char tmp = string[i];
  string[i] = string[j];
  string[j] = tmp;
}


int Partition(char* string, int low, int high) {
  char pivot = string[low];
  int leftwall = low;
  int i;
  for (i = low + 1; i <= high; i++) {
    if (string[i] < pivot) {
      leftwall++;
      Swap(string, i, leftwall); // TODO
    }
  }
  Swap(string, low, leftwall);
  return leftwall;
}

void Quicksort(char* string, int low, int high) {
  if (low < high) {
    int pivot_location = Partition(string, low, high);
    Quicksort(string, low, pivot_location);
    Quicksort(string, pivot_location+1, high);
  }
}


