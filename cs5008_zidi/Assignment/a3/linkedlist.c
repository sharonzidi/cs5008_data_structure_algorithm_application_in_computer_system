#include <stdio.h>
#include "linkedlist.h"

LinkedListPtr CreateLinkedList(){
    LinkedListPtr list = (LinkedListPtr)malloc(sizeof(LinkedListPtr));
    list->head = NULL;
    return list;
}

void DestroyLinkedList(LinkedListPtr list){
    LinkedListNodePtr curNode = list->head;
    LinkedListNodePtr next = curNode->next;
    while (curNode != NULL) {
        DestroyLinkedListNode(curNode);
        curNode = next;
        // Check that curNode is not NULL 
        if (curNode != NULL) {
            next = curNode->next;
        }
    }
    free(list);
}


unsigned int NumElementsInLinkedList(LinkedListPtr list) {
    return list->num_elements;
}

int InsertLinkedList(LinkedListPtr list, int num) {
    LinkedListNodePtr node;

    // TODO: Check that node isn't NULL
    if (list->head != NULL) {
        list->head->prev = node; // Points head of list to new node. 
        node->next = list->head; // New node now points at the old head
        list->head = node;
    } else {
        list->head = node;
  }
    return 0;
}

int AppendLinkedList(LinkedListPtr list, int num) {
    LinkedListNodePtr node;

    // TODO: Check that node isn't NULL
    if (list->tail != NULL) {
        list->tail->next = node; // Points head of list to new node. 
        node->prev = list->tail; // New node now points at the old head
        list->head = node;
    } else {
        list->tail = node;
  }
    return 0;
}

int PrintLinkedList(LinkedListPtr list) {
    LinkedListNodePtr curNode = list->head;
    while (curNode != NULL) {
    // Print node
        printf("%p\t%d:%p\t%p\n", curNode->prev,
            curNode->data,
            curNode,
            curNode->next);
        curNode = curNode->next;
  }
    return 0;
}

LinkedListNode* CreateLinkedListNode(int data) {
    LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    node->data = data;
    node->prev = NULL;
    node->next= NULL;
    return node;
}

int DestroyLinkedListNode(LinkedListNode *node) {
    printf("destroying node: %d\n", node->data);
    free(node);
    return 0;    
}

int RemoveLLElem(LinkedListPtr list, LinkedListNodePtr ptr) {
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;

    return 0;
}