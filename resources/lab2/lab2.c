#include <stdio.h>
#include <string.h>

void crop_hi(int* arr, int len, int ceiling) {
  int i;
  for (i = 0; i < len; i++) {
    if (arr[i] > ceiling) {
      arr[i] = ceiling;
    }
  }
}

void add2(int* arr, int len) {
  int i;
  for (i=0; i < len; i++) {
    arr[i] += 2;
  }
}


void print(const arr[], const int size) {
  int i;
  //  strlen()
  printf("[");
  for (i = 0; i < size; i++) {
    printf("%d, ", arr[i]); 
  }
  printf("]\n");
}

int main() {
  // Declaring
  int arr[] = {15, 2, 34, 19, 4, 6};
  print(arr, 6);
  crop_hi(arr, 6, 19);
  print(arr, 6);

  
  /*

  
  int i;
  
  int arr2[5] = {0};
  
  /*
  // Initalize
  for (i = 0; i < 5; i++) {
    arr[i] = i;
  }
  */

  //  printf("%d\n",  arr);

  /*
  // Use the array
  // Iterate:
  for (i = 0; i < 5; i++) {
    printf("%p\t%d\t%d\t%c\n", &arr[i], &arr[i], arr[i], arr[i]);
  }
  */
  return 0;
}
