#include<stdio.h>

void printArr(int arr[], int size){
    //print the values of the array to the console
    //
    //Explanation on why this doesn't return 40
    //When we define an array, we can call 'sizeof' to get the size
    //(in bytes) of the array, which is derived from the size of the arry
    // multiplied by the size of the type its storing. In the case of our int array,
    // since ints are 4 bytes, the overall size of the array, which has 10 elements, 
    // is 40 bytes. When we pass that array to a function, the array is converted
    // to a pointer to its first element. That is why the below sizeof returns 8, 
    // instead of 40.
    //
    // How do we get around this? We can use sizeof in the same scope of the array
    // definition, and pass that value into any function which requires the size of 
    // the array.  I've changed the code below to refect that.
   printf("the size of pointer to the array is %d \n", sizeof arr);
    int i; // what is wrong with this?

    for(i=0; i<size; i++) {
        printf("The value I printed here is [%d] \n", arr[i]);
    }
}

void print(int i) {
    printf("The value passed was [%d] \n", i);
}

int main() {
    printf("Hello World \n");

    char testVar = 'A';
    print(testVar);

    printf("The value is [%d] \n", testVar);

    int testArr[10];

    printf("The size of testArr is %d \n", sizeof testArr);


    int i;

    for(i=0; i<10; i++) {
        testArr[i] = i + 2;
   
//    printf("The value at element [%d] is %d \n", i, testArr[i]);
//        printf("%p \t %d \n", &testArr[i], testArr[i]);
   }
/*        printf("%p \n", &testArr);
        printf("The %dth element is [%d] \n", 5, testArr[4]);
        printf("%p \n", 0x7ffdeffd3570);
*/
   int arrSize = sizeof testArr / sizeof testArr[0];

   printArr(testArr, arrSize); // the size of the array is passed into the function   
	return 0;
}
