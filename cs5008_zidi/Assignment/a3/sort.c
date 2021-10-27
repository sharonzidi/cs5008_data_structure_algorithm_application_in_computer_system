#include <stdio.h>

#include "linkedlist.h"

void Swap(LinkedListNodePtr n1, LinkedListNodePtr n2) {
  n2->prev = n1->prev;
  n1->prev->next = n2;
  n1->prev = n2;
  n1->next = n2->next;
  n2->next = n1;
}

LinkedListPtr Sort(LinkedListPtr list) {
int i, j;
int n = NumElementsInLinkedList(list);
for (i = 0; i < n-1; i++)
    for(j = 0; j < n-i-1; j++){
        if (list->head > list->head->next) {
            Swap(list->head, list->head->next);
        }
    }
}


