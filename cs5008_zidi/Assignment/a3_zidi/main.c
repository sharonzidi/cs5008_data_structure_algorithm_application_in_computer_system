#include <stdio.h>
#include "sort.h"
#include "linkedlist.h"


int main() {
  printf("size of different\n");// just for my future review
  printf("%d\n", sizeof(struct ll_head));
  printf("%d\n", sizeof(LinkedListPtr));
  printf("Test 1\n");
  LinkedListPtr ll = CreateLinkedList();
  InsertLinkedList(ll, 2);
  InsertLinkedList(ll, 1);
  AppendLinkedList(ll, 3);
  AppendLinkedList(ll, 4);
  AppendLinkedList(ll, 5);
  AppendLinkedList(ll, 4);
  AppendLinkedList(ll, 0);
  printf("unsorted:\n");
  PrintLinkedList(ll);
  printf("\n\n");
  //LinkedListNodePtr p = makeNode(5, NULL);
  //RemoveLLElem(ll,p);
  //printf("test RemovellElem, it should remove nothing\n");
  //PrintLinkedList(ll);
  //printf("\n\n");
  printf("sorted:\n");
  Sort(ll);
  PrintLinkedList(ll);
  //DestroyLinkedListNode(p);
  DestroyLinkedList(ll);
  printf("-----------------------------");
  LinkedListPtr ll2 = CreateLinkedList();
  InsertLinkedList(ll2, 5);
  InsertLinkedList(ll2, 4);
  AppendLinkedList(ll2, 3);
  AppendLinkedList(ll2, 2);
  AppendLinkedList(ll2, 1);
  printf("\nTest 2\nunsorted:\n");
  PrintLinkedList(ll2);
printf("\n\n");
  Sort(ll2);
  printf("sorted: ");
  PrintLinkedList(ll2);
  printf("\n\n");
  DestroyLinkedList(ll2);

  printf("-----------------------------");
  printf("\nTest 3\n");
  int i, n;
  time_t t;

  n = 50;

  /* Intializes random number generator */
  srand((unsigned) time(&t));
  LinkedListPtr randomList = CreateLinkedList();
  /* Print 5 random numbers from 0 to 49 */
  for( i = 0 ; i < n ; i++ ) {
    int randomNum= (1 + rand() % (100 - 1));
    AppendLinkedList(randomList, randomNum);
  }
  printf("radom list:\n");
  PrintLinkedList(randomList);
  Sort(randomList);
  printf("sorted:\n");
  PrintLinkedList(randomList);
  DestroyLinkedList(randomList);
  return 0;
  }
