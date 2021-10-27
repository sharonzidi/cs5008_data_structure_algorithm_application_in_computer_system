#include <stdio.h>
#include "sort.h"
#include "linkedlist.h"

int main() {
    
    LinkedListNodePtr node = CreateLinkedListNode((rand() % (100 - 1 + 1)) + 1);
    LinkedListPtr list = CreateLinkedList();
    for (LinkedListNodePtr cur = node; cur != NULL; cur = cur->next) {
        AppendLinkedList(list, (rand() % (100 - 1 + 1)) + 1); 
    }
    PrintLinkedList(list);

    list = Sort(list);
    PrintLinkedList(list);

//   LinkedListNode n1 = {"n1", NULL, NULL}; // CreateNode()
//   LinkedListNode n2 = {"n2", NULL, NULL};
//   LinkedListNode n3 = {"n3", NULL, NULL};

//   LinkedListPtr list = {NULL};

//   printf("\n\n");

//   LinkedListPtr list = CreateLinkedList();
//   LinkedListNodePtr n1 = CreateLinkedListNode(1);
//   LinkedListNodePtr n2 = CreateLinkedListNode(2);
//   LinkedListNodePtr n3 = CreateLinkedListNode(3);
}
