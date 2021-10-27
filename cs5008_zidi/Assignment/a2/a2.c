#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a2.h"
#include <string.h>


// YOUR CODE GOES HERE

// Print the string <first> <middle> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Ivan Bitdiddle".
//
//  If the middle name is NULL, then print:
//  "Ben Bitdiddle"
//
//  name: a pointer to a Name
void Big(Name *name) {

    if(name->middle != NULL) {
        printf("%s %s %s.\n", name->first, name->middle, name->last);
    } else {
        printf("%s %s.\n", name->first, name->last);
  }
}

// Print the string <last>, <first>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Bitdiddle, Ben".
//
// name: a pointer to a Name
void Last(Name *name) {
    printf("%s %s.\n", name->last, name->first);
}

// Print the string <first> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Bitdiddle".
//
// name: a pointer to a Name
void Reg(Name *name) {
    printf("%s %s.\n", name->first, name->last);
}

// Print the string <first> <middle-initial>. <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben I. Bitdiddle".
//
// If middle name is NULL, print:
// "Ben Bitdiddle"
//
// name: a pointer to a Name
void Mid(Name *name) {
    if(name->middle != NULL) {
        printf("%s %c. %s.\n", name->first, name->middle[1], name->last);
    } else {
        printf("%s %s.\n", name->first, name->last);
    }
}

// Print the first name only.
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben".
//
// name: a pointer to a Name
void Small(Name *name){
    printf("%s.\n", name->first);
}

// Given a format char, print the given
// name in the format specified by char.
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
void FormatName(Name *name, char format){

    if(format == 'B') {
        Big(name);
    } else if(format == 'L') {
        Last(name);
    } else if(format == 'R') {
        Reg(name);
    } else if(format == 'M') {
        Mid(name);
    } else if(format == 'S') {
        Small(name);
    } 
 }


char* BigFill(Name *name, char *dest) {

    if(name->middle != NULL) {
        
        strcpy(dest, name->first);
        strcpy(dest, name->middle);
        strcpy(dest, name->last);
    } else {
        strcpy(dest, name->first);
        strcpy(dest, name->last);
  }
}

char* LastFill(Name *name, char *dest) {
    strcpy(dest, name->last);
    strcpy(dest, name->first);
}

char* RegFill(Name *name, char *dest) {
    strcpy(dest, name->last);
    strcpy(dest, name->first); 
}

char* MidFill(Name *name, char *dest) {
    if(name->middle != NULL) {
        strcpy(dest, name->first);
        strcpy(dest, name->middle[1]);
        strcpy(dest, name->last);
    } else {
        strcpy(dest, name->first);
        strcpy(dest, name->last);
    }
}

char* SmallFill(Name *name, char *dest) {
    strcpy(dest, name->first); 
}

// Given a name, a format and a destination array,
// put the properly formatted name in the destination
// array, not printing anything on the screen.
//
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// dest: a pointer to an array that is guaranteed to be big enough
// to hold the formatted name
void FillName(Name *name, char format, char *dest) {
    if(format == 'B') {
         BigFill(name, dest);
     } else if(format == 'L') {
         LastFill(name, dest);
     } else if(format == 'R') {
         RegFill(name, dest);
     } else if(format == 'M') {
         MidFill(name, dest);
     } else if(format == 'S') {
         SmallFill(name, dest);
     }

//   int i;
//   char* formattedName = FormatName(name, format);
//   for (i = 0; i < sizeof(dest); i++) {
//       dest[i] = (char*)malloc(sizeof(formattedName));
  }
