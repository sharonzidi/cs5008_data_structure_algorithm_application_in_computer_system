#include <inttypes.h>
#include "Hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort.h"

#define MAX_LINE_LENGTH 80

int main() {
    Hashtable ht = CreateHashtable(100);

    char *path;
    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_count = 0;

    FILE *file;

    if ((file = fopen("wordsFull.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    char sorted[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line[strlen(line)-1] = '\0';
        snprintf(sorted, strlen(line)+1, "%s", line);
        Quicksort(sorted, 0, strlen(sorted)-1);
        put(ht, sorted, line);
    }
    fclose(file);

    /* Add a trailing newline to lines that don't already have one */
    //if (line[strlen(line) - 1] != '\n')
    //    printf("\n");

    PrintHashtable(ht);
    return 0;

}

