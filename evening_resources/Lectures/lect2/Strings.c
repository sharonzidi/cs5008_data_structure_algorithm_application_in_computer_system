#include <stdio.h>

void printString(char* s){
    printf("The address is [%p] \n", &s); 
    printf("The value is: %s \n", s);
}

int main() {
    char charArr[] = "test";
    printf("The address is [%p] \n", &charArr); 
    printString(charArr);
}
