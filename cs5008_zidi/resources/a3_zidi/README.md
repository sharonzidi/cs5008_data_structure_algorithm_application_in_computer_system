# HW3 Implementing Sorts
## How to build and run the code:
* use **make** to compile
* use **./sort** to run
## An example of the input and output:
<pre><code>
-bash-4.2$ ./sort
size of different
24
8
Test 1
unsorted:
1 2 3 4 5 4 0


sorted:
0 1 2 3 4 4 5
-----------------------------
Test 2
unsorted:
4 5 3 2 1


sorted: 1 2 3 4 5


-----------------------------
Test 3
radom list:
6 1 87 43 28 73 13 82 77 19 2 3 38 47 70 34 45 94 62 81 46 39 50 60 65 88 60 50 61 94 27 64 94 14 7 22 84 19 2 59 35 4 61 71 48 30 5 92 24 64
sorted:
1 2 2 3 4 5 6 7 13 14 19 19 22 24 27 28 30 34 35 38 39 43 45 46 47 48 50 50 59 60 60 61 61 62 64 64 65 70 71 73 77 81 82 84 87 88 92 94 94 94
</code></pre>
The random list could be different from the above.
## Description of the files in the directory
* linkedlist.c   
* linkedlist.h  
* main.c   
* Makefile  
* sort.c 
* sort.h
## Links to references, acknowledgments, and other resources
1. https://www.geeksforgeeks.org/insertion-sort/
2. https://www.geeksforgeeks.org/insertion-sort-doubly-linked-list/
## About how much time you spent on this assignment
4 days. 
## What was the most challenging part of this assignment? 
The most challenging parts are:
1. Figure out when to free and which to free; which size should I use to malloc
2. Figure out how to connect nodes
3. Figure out all the cases that may happen
4. Figure out the implementation of insertion sort using pointers.
5. Debug
6. Use emacs 
## [Optional] What did you like about this assignment?
This assignment give us the opportunity to try implement sort via linkedlist. I have done sorting via array but not likedlist. It provides me new insight.
## [Optional] How could this assignment be improved?
It is challenging for me who just touch a new language in C, to implemnt an algorithm. Because I am still not fully understand the pointer, how C use memory.
I am a kind of person who is eager to fully understand every technique before doing the task. Therefore, it took me a lonng time to read through the info from books and from Internet.
But it's acceptable, since the homework is extended. 
