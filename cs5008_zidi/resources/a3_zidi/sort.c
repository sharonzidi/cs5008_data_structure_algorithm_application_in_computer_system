#include <stdio.h>

#include "linkedlist.h"

void SwapByValue(LinkedListNodePtr n1, LinkedListNodePtr n2);
void sortedInsert(LinkedListPtr list, LinkedListNodePtr newNode) {
  LinkedListNodePtr curr;
  if (list == NULL) {
    return;
  }
  if (list->head  == NULL) {
    list->head = newNode;
    //printf("empty node add\n");
  } else if (list->head->data >= newNode->data) {
    newNode->next = list->head;
    newNode->next->prev = newNode;
    list->head = newNode;
    //printf("add to first\n");
  } else {
    // printf("add to midd\n");
    curr = list->head;
    while (curr->next != NULL && curr->next->data < newNode->data){
      curr = curr->next;
    }
      newNode->next = curr->next;
      if (curr->next != NULL) {
        newNode->next->prev = newNode;
      }
      curr->next = newNode;
      newNode->prev = curr;
    }
  }
//Insertion sort, ascending order
void Sort(LinkedListPtr list) {
  if (list==NULL) {
    return;
  }
  LinkedListPtr result = CreateLinkedList();
  LinkedListNodePtr curr = list->head;
  while (curr != NULL){
    LinkedListNodePtr next = curr->next;
    curr->prev = curr->next = NULL;
    sortedInsert(result, curr);
    curr = next;
  }
  list->head = result->head;
  free(result);
}
