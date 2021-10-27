
// Zidi Xia
// CS5008 2021 Spring
// Mar 10 2021
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"


// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode *CreateLinkedListNode(char* key, char *value)
{
    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    node->data = CreateLinkedList();
    return node;
}

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node)
{
    node->next = NULL;
    node->prev = NULL;
    node->key = NULL;
    node->value = NULL;
    free(node);
    if (node == NULL)
    {
        return 0;
    } 
    return 1;
}

// Removes a given element from a linkedList.
//
// INPUT: A pointer to a linked list.
// INPUT: A ListNodePtr that points to a LLNode to be removed from the list.
//
// Returns 0 if the destroy was successful
//   (primarily that the provide Ptr is in the list and could be free'd).
int RemoveLLElem(LinkedList list, LinkedListNodePtr ptr)
{
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);

    if (ptr == NULL)
    {
        return 0;
    }
    return -1;
}

// ======================================================
// LinkedList: A Doubly-Linked List
// ======================================================

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy and free the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error.
LinkedList CreateLinkedList()
{
    LinkedListHead *list = (LinkedListHead *)malloc(sizeof(LinkedListHead));
    list->head = NULL;
    return list;
}

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed. Payload_free_function will
// be used to free the payloads in the list.
// See: http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#functionPointers
// OR: change your LinkedList such that it holds a specific payload type,
// and doesn't need to free the payload.
//
// INPUT: A pointer to a LinkedList.
// INPUT: A pointer to a function used to free the payload.
//
// Returns 0 if the destroy was successful; non-zero for failure.
int DestroyLinkedList(LinkedList list)
{
    LinkedListNodePtr curNode = list->head;
    LinkedListNodePtr nextNode = curNode->next;
    while (curNode != NULL)
    {
        DestroyLinkedListNode(curNode);
        curNode = nextNode;

        if (curNode != NULL)
        {
            nextNode = curNode->next;
        }
    }

    if (list == NULL)
    {
        return 0;
    }
    return 1;
}

// Returns the number of elements in the linked list.
//
// INPUT: A LinkedList
//
// Returns the number of elements in the list.
unsigned int NumElementsInLinkedList(LinkedList list)
{   
    int num = 0;
    LinkedListNodePtr curNode = list->head;
    while (curNode != NULL)
    {
        num++;
        curNode = curNode->next;
    }
    return num;
}

// Adds an element to the head of a LinkedList, with the string
// as the given pointer.
// The customer is responsible for allocating the string.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A pointer to a string for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int InsertLinkedList(LinkedList list, LinkedListNodePtr newNode)
{
    // LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    if (list->head != NULL)
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        newNode->prev = NULL;
    }
    list->head = newNode;
    if (list->head == newNode)
    {
        return 0;
    }
    return 1;
    
}

// Copies the pointer to the payload at the head of a list
// to the provided dataPtr, and removes the head node from the list.
//
// INPUT: A pointer to the LinkedList.
// INPUT: A pointer to a char* that will be updated
//        with the char* at the head of the list.
//
// Returns 0 if the pop was successful; non-zero for failure.
int PopLinkedList(LinkedList list, char **dataPtr)
{
    // dataPtr = list->head;
    DestroyLinkedListNode(list->head);
    if (list->head == NULL)
    {
        return 0;
    }
    return -1;
}
