#include<stdio.h>

int main() {

  char* first = "first";

  int i;
  for (i = 0; i < 5; i++ ) {
    printf("%p, %c\n", &first[i], first[i]);
  }

  first[0] = "F";
  
  char second[10] = "second";
  for (i = 0; i < 10; i++ ) {
    printf("%p, %c\n", &second[i], second[i]);
  }

  second[0] = "S";


  char* a_bunch[5];

  a_bunch[0] = "alice";
  a_bunch[1] = "bob";
  
  
}
