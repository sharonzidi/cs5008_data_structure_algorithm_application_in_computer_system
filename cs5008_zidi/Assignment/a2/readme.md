
# Assignment 2: Working with structs, functions, and header files

## Objectives

* Start working with structs
* Doing more advanced things with strings
* Working with functions and function prototypes
* Working with header files


## Summary/Overview

In this assignment, you'll start playing around with structs and string.

## Relevant Reading

* [Pointers and Memory](http://cslibrary.stanford.edu/102/PointersAndMemory.pdf) by Nick Parlante. Read Section 1 - 4; Ignore the "Extra Optional Material" in all sections unless you want to read it.

* [Yale Notes, Pointers](http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#pointers), Section 4.9, through 4.9.5.
* [Yale Notes, Strings](http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#strings).

## Details

### Warm-up: Start working with Pointers

It seems like many of you are going into the world of pointers before we get there, so this week we'll guide your way. This hasn't entirely been covered in class, but this exercise should help a ton. Follow the reading, ask questions on Piazza, and ask TAs/instructors.

This intro (Links to an external site.) to Pointers and Memory by Nick Parlante is a good intro (Sections 1, 2, 3).

Create a file named something like pointers.c in an a2 folder. Use this to practice with the code in the readings (either by Parlante or the Yale notes). Check this in so we can see your progress.

## Part A: Check out starter code and copy into your repo
The CS 5008 resources repo has some starter code for this assignment. Check it out (clone into its own folder/local repo), and copy the files from the a3 folder over to your own personal repo.

## Part B: Work with structs and the string library
We briefly introduced structs in class this week. In the assignment, start playing around with structs.

In the provided .h file, we have provided a definition for a struct named Name:

```
// A Name consists of first, last, and
// and an OPTIONAL middle name.
struct Name {
  char *first;
  char *middle;
  char *last;
  int age; 
};

typedef struct Name Name;
```

There are a couple things to note here:

* The name of the struct is ```Name```, with a capital N, per our style guide.
* The ```typedef``` statement: To refer to a struct in code, you have to write ```struct Name```, not just ```Name```. The ```typedef``` statement allows you to tell C to replace one phrase with a specified name. Here, we're telling C to replace ```struct Name``` with the word ```Name```. That means, wherever we write ```Name``` in our code, C will replace it with ```struct Name```.
* We usually have a pointer to a struct. We'll talk more about pointers later, but what's relevant is that to access a field of a pointer to struct, we use the arrow operator: ```->```. That means, if I have a variable ```Name *some_name```, to do something with the ```age``` field, I use ```some_name->age```.

In addition to the ```Name``` definition, ```a2.h``` has the function prototypes of the functions you need to implement. The file ```a2_test.c``` includes some functions that use your functions. At any point, you can run ```make test``` to run the test that uses your functions.

You're also provided with a ```Makefile``` this time (we'll talk about how they work in the lab!).

Try implementing the functions from the top of the file first.

# Submit your code to git by pushing

* Pull your repo to get any files added by TAs
* Add the new files in the ```a2``` directory to git.
* DO NOT push any executables (the files that are output after you compile, and the ones that you run). You will lose points if you do.
* Commit the changes: ```git commit -am 'adding a2 code'```. (You can and should do this many times throughout the process of doing a3)
* Push the changes to the remote git repo: ```git push```
* When you're all done and ready to submit your code, tag your repo: ```git tag 'a2-final'```, then ```git push origin a2-final``` to push the final tag to the repo so we can see it.
* Submit the URL to this tag on Canvas, preferably as a link. 
* Your name and the date that you are submitting should be at the top of the source file containing the main function.

## Common questions 
* **Can I create helper functions? Do I include the function prototype in the .h file? Do I have to test the helper functions I create?** Yes, you can create helper functions. You can include the function prototype in the .h file, but you don't have to-- you can either put the prototype or the definition at the top of the .c file. We won't grade you on the testing of your helper function, but you *are* responsible for making sure it works correctly. 
* **Why does my program working depending on how I initialize the strings?** Working with strings in C can be tricky. They are either mutable or immutable (able to modify them or not) depending on how they are initialized. Refer to notes in class about initializing strings. 
* ```snprintf``` vs ```strcpy```: What should I use? Please use ```snprintf```. 
