#include<stdio.h>

void main(){
  int arr[10];

  int i;

  for(i=0; i<10; i++){
    arr[i] = i;
  }

  int j;

  for(j=0; j<10; j++){
    printf("The element at index [%d] is %d \n", arr[j], j);
  }
}
