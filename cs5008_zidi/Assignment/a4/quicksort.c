#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h> // for sleep()
#include <sys/time.h>
#include <string.h>

int num_partition_calls = 0;
int num_quicksort_calls = 0;
int num_comparisons = 0;
int num_insert_comparations = 0;

void Swap(int *array, int ind1, int ind2)
{
    int tmp = array[ind1];
    array[ind1] = array[ind2];
    array[ind2] = tmp;
}

int Partition(int *data, int low, int high)
{
    num_partition_calls++;
    int pivot = data[low];
    int leftwall = low;
    int i;
    for (i = low + 1; i <= high; i++)
    {
        num_comparisons++;
        if (data[i] < pivot)
        {
            leftwall++;
            Swap(data, i, leftwall);
        }
    }
    Swap(data, low, leftwall);
    return leftwall;
}

// Alg0
void Quicksort(int *data, int low, int high)
{
    num_quicksort_calls++;
    if (low < high)
    {
        int pivot_location = Partition(data, low, high);
        Quicksort(data, low, pivot_location);
        Quicksort(data, pivot_location + 1, high);
    }
}

void PrintArray(int *array, int num_elems)
{
    int i;
    printf("[");
    for (i = 0; i < num_elems; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int CheckArray(int *array, int num_elems)
{
    int i;
    for (i = 1; i < num_elems; i++)
    {
        if (array[i] < array[i - 1])
        {
            printf("NOT SORTED!!!\n");
            return 0;
        }
    }
    printf("SORTED!!\n");
    return 1;
}

// shuffle
void Randomize(int *array, int num_elems)
{
    int i;
    for (i = num_elems - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Swap(array, i, j);
    }
}

//Alg1
void ShuffleAndSort(int *data, int low, int high, int num_elems)
{
    Randomize(data, num_elems);
    Quicksort(data, low, high);
}

//Alg2 MedianPartition Quick Sort
int MedianPartition(int *data, int low, int high)
{
    num_partition_calls++;
    int mid = low + (high - low) / 2;
    Swap(data, low, mid);

    int pivot = data[low];
    int leftwall = low;
    int i;
    for (i = low + 1; i <= high; i++)
    {
        num_comparisons++;
        if (data[i] < pivot)
        {
            leftwall++;
            Swap(data, i, leftwall);
        }
    }
    Swap(data, low, leftwall);
    return leftwall;
}

void MedianQuicksort(int *data, int low, int high)
{
    num_quicksort_calls++;
    if (low < high)
    {
        int pivot_location = MedianPartition(data, low, high);
        MedianQuicksort(data, low, pivot_location);
        MedianQuicksort(data, pivot_location + 1, high);
    }
}

// Alg3
void insertionSort(int *data, int num_elems)
{
    int i;
    for (i = 1; i < num_elems; i++)
    {
        int j;
        for (j = i; j > 0 && data[j] < data[j - 1]; j--)
        {
            num_insert_comparations++;
            Swap(data, j, j - 1);
        }
    }
}

void generateRandomIntArray(int *integers, int num_elems)
{
    int j;
    for (j = 0; j < num_elems; j++)
    {
        int val = (rand() % 10000) + 10;
        integers[j] = val;
    }
}

int timeDiff(struct timeval begin, struct timeval end)
{
    long seconds = (end.tv_sec - begin.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);
    return (int)(seconds * 1000000 + micros);
}

int main(int argc, char *argv[])
{
    int num_elems[] = {16, 32, 64, 128, 512, 1024, 2048};
    char *flag = argv[1];
    int k;
    for (k = 1; k < strlen(flag); k++)
    {
        int time_array[7];
        int i;
        for (i = 0; i < 7; i++)
        {
            int *integers = (int *)malloc(sizeof(int) * num_elems[i]);
            srand(time(0)); // (unsigned)time(&t));
            generateRandomIntArray(integers, num_elems[i]);

            struct timeval begin, end;
            gettimeofday(&begin, NULL);
            switch (flag[k])
            {
            case 'a':
                Quicksort(integers, 0, num_elems[i] - 1);
                break;
            case 'b':
                ShuffleAndSort(integers, 0, num_elems[i] - 1, num_elems[i]);
                break;
            case 'c':
                MedianQuicksort(integers, 0, num_elems[i] - 1);
                break;
            case 'd':
                insertionSort(integers, num_elems[i] - 1);
                break;
            }

            gettimeofday(&end, NULL);
            time_array[i] = timeDiff(begin, end);

            free(integers);
        }

        printf("16 32 64 128 512 1024 2048 \n");
        printf("----------------------------\n");
        printf("Alg -%c: ", flag[k]);
        PrintArray(time_array, 7);
        printf("\n");
    }

    return 0;
}
