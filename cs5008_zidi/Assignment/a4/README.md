# Assignment 4: Quicksort Experimentation

Zidi Xia

## How to run the code
```
- gcc quicksort.c
- ./a.out -a (To sort with algorithm a:Quicksort)
- ./a.out -b (To sort with algorithm b:Shuffle and Quicksort)
- ./a.out -c (To sort with algorithm c:Quicksort with Median as Pivot)
- ./a.out -d (To sort with algorithm d:Insertion Sort)
- ./a.out -abcd (To sort with algorithm a,b,c,d)
```
## Finial Result:
```
16 32 64 128 512 1024 2048 
----------------------------
Alg -a: [1 2 4 8 45 99 233 ]

16 32 64 128 512 1024 2048 
----------------------------
Alg -b: [2 2 5 11 51 115 240 ]

16 32 64 128 512 1024 2048 
----------------------------
Alg -c: [1 2 5 11 56 113 244 ]

16 32 64 128 512 1024 2048 
----------------------------
Alg -d: [1 2 6 45 429 1537 6715 ]
```
## Summary
```

In this assignment, I found that different sorting algorithm perform the same but they have different number of partition calls, quicksort calls, and comparisons calls.

From the result, I found that the number of comparisions for quick sort is less than insertion sort. When I set the number of elements in array to a small number such as 10, there's no big difference between the comparisions number. However, when I set 100, Quicksort comparisons calls: 1570 and Insertion sort is 2455.
```