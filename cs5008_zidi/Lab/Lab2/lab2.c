#include <stdio.h>
#include <string.h> 

/**
 * Write a function that replaces all numbers greater
 * than ceiling in arr with ceiling.
 *
 * Precondition(s):
 * - len > 0 (i.e. arrays MUST have at least one element)
 *
 * Example(s):
 * - crop_hi([1, 2, 3, 4], 4, 2) :: [1, 2, 2, 2]
 * - crop_hi([-3, 17,  7, -12, 10], 5, 8) :: [-3, 8, 7, -12, 8]
 *
 * @param arr     array of integers
 * @param len     length of arr
 * @param ceiling upper limit for ints in array
 */
void crop_hi(int* arr, int len, int ceiling) {
    int i;

    printf("[ ");
    for ( i = 0; i < len; i++ ) {
        if (ceiling < arr[i]) {
            arr[i] = ceiling;        
        }
        printf("%d ", arr[i]);
    }
    printf("]\n");
}


/**
 * Swaps the last int in arr with the middle element in arr.
 *
 * Precondition(s):
 * - len > 0 (i.e. arrays MUST have at least one element)
 *
 * Example(s):
 * - swap_mid_back([1, 2, 3], 3) :: [1, 3, 2]
 * - swap_mid_back([-4, 3, 0, 1], 4) :: [-4, 1, 0, 3]
 *
 * @param arr array of integers
 * @param len length of arr
 */
void swap_mid_back(int* arr, int len) {
    int temp;
    int i;
    
    printf("[ ");
    if (len % 2 != 0) {
        temp =  arr[(len+1)/2 - 1];
        arr[(len+1)/2 -1] = arr[len - 1];
        arr[len - 1] = temp;
    } else {
        temp = arr[len/2 - 1];
        arr[len/2 - 1] = arr[len - 1];
        arr[len - 1] = temp;
        }

    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
        }

    printf("]\n");
    }

/**
 * Replaces all digits in a string with a '*'. 
 *
 *
 * Example(s):
 * - redact("The part failed 58% of the time") ::
 *          "The part failed **% of the time"
 * - redact("There were 13 As in the class") :: "There were ** As in the class"
 *
 * @param  str      host string for old_char
 */
void redact(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            str[i] = '*';
        }
    }
}

int main() {
    // Declaring
    int arr[] = {15, 2, 34, 19, 4, 6};
    int arr_2[] = {15, 2, 34, 19, 4, 6};
    char str[] = "The part failed 58% of the time";

    // crop_hi function
    crop_hi(arr, 6, 19);
    
    // swap function
    swap_mid_back(arr_2, 6);

    // redact function
    redact(str);
    printf("%s\n",str);

    return 0;
}
