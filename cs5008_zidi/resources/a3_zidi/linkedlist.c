#include <stdio.h>
#include "linkedlist.h"

// ======================================================
// LinkedList: A Doubly-Linked List 
// ======================================================

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error. 
LinkedListPtr CreateLinkedList() {
  LinkedListPtr newList = (LinkedListPtr) malloc(sizeof(struct ll_head));
  if (newList == NULL) {
    return NULL;
  }
  newList->head = NULL;
  newList->tail = NULL;
  newList->num_elements = 0;
  return newList;
}

void DestroyNode(LinkedListNode* n) {
  if (n == NULL) {
    return;
  }
  free(n);
}

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed.
//
// INPUT: A pointer to a LinkedList.
void DestroyLinkedList(LinkedListPtr list) {
  if (list == NULL) {
    return;
  }
  LinkedListNode* curNode = list->head;
  LinkedListNode* nextNode = curNode->next;
  while(curNode != NULL) {
    DestroyNode(curNode);
    curNode = nextNode;
    if (curNode != NULL){
      nextNode = curNode->next;
    } 
  }
  free(list);
}


// Returns the number of elements in the linked list. 
// 
// INPUT: A LginkedList 
// 
// Returns the number of elements in the list. 
unsigned int NumElementsInLinkedList(LinkedListPtr list) {
  if (list == NULL) {
    return -1;
  }
  return list->num_elements;
}

LinkedListNode* makeNode(int data, LinkedListNodePtr next) {
  LinkedListNodePtr newNode = (LinkedListNodePtr) malloc
                           (sizeof(LinkedListNode));
  if (newNode == NULL){
    return NULL;
  }
  newNode->data = data;
  newNode->next = next;
  return newNode;
}

// Adds an element to the head of a LinkedList, with the given value
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int InsertLinkedList(LinkedListPtr list, int n) {
  if (list == NULL) {
    return 1;
  }
  /*
  LinkedListNodePtr newNode = makeNode(n, NULL);
  LinkedListNodePtr follwingNode = list->head;
  list->head= newNode;
  follwingNode->prev = newNode;
  newNode->next = follwingNode;
  */
  LinkedListNodePtr newNode = makeNode(n, NULL);
  if (list->head != NULL){

    list->head->prev = newNode;
    newNode->next = list->head;
    list->head = newNode;
  } else {
    list->head = newNode;
    list->tail = newNode;
    newNode->next = NULL;
  }
  newNode->prev = NULL;
  list->num_elements += 1;
  return 0;
}

// Adds an element to the tail of a LinkedList, with the given value.
//valgrind --leak-check=full
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int AppendLinkedList(LinkedListPtr list, int n) {
  if (list == NULL) {
    return 1;
  }
  LinkedListNodePtr newNode = makeNode(n, NULL);
  if (list->tail == NULL) {
    list->tail = newNode;
    list->head = newNode;
    newNode->prev = NULL;
  } else {
    newNode->prev = list->tail;
    newNode->prev->next = newNode;
    list->tail = newNode;
  }
  list->num_elements += 1;
  return 0;
}

// Prints out the given LinkedListPtr. 
//
// INPUT: A pointer to the LinkedList that will be printed out.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int PrintLinkedList(LinkedListPtr list) {
  if (list == NULL) {
    return 1;
  }
  LinkedListNodePtr curr = list->head;
  while(curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode* CreateLinkedListNode(int data) {
  return makeNode(data, NULL);
}
// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node) {
  if (node == NULL) {
    return 1;
  }
  DestroyNode(node);
  return 0;
}

int contain(LinkedListPtr list, LinkedListNodePtr ptr);
// Removes a given element from a linkedList.
//
// INPUT: A pointer to a linked list.
// INPUT: A ListNodePtr that points to a LLNode to be removed from the list.
//
// Returns 0 if the destroy was successful
//   (primarily that the provide Ptr is in the list and could be free'd).
int RemoveLLElem(LinkedListPtr list, LinkedListNodePtr ptr) {
  if (list == NULL || ptr == NULL) {
    return 1;
  }
  if (list->head == NULL) {
    return 1;
  }
  if (contain(list, ptr) == 0){
    if (ptr == list->head) {
      list->head = ptr->next;
      list->head->prev = NULL;
    } else if (ptr == list->tail) {
      list->tail = ptr->prev;
      list->tail->next = NULL;
    } else {
      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
    }
  list->num_elements -= 1;
  free(ptr);
}
  return 1;
}

int contain(LinkedListPtr list, LinkedListNodePtr ptr) {
  if (list == NULL|| ptr == NULL) {
    return 1;
  }
  LinkedListNodePtr curr = list->head;
  while(curr != NULL) {
    if (curr == ptr) {
      return 0;
    }
    curr = curr->next;
  }
  return 1;
}
