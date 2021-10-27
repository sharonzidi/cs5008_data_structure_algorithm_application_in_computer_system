#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<stdint.h>

struct ll_head;
typedef struct ll_head *LinkedList;

// This struct represents an individual node within a linked list.  A node
// contains next and prev pointers as well as a customer-supplied payload
// pointer.
typedef struct ll_node {
    char* key; 
    char* value; // Pointer to a string, most likely on the heap
    struct ll_node *next;     // next node in list, or NULL
    struct ll_node *prev;     // prev node in list, or NULL
    LinkedList data;
    // struct ll_node *array;     // newNode node in list, or NULL
} LinkedListNode, *LinkedListNodePtr;

// This struct represents the entire linked list.  We provided a struct
// declaration (but not definition) in LinkedList.h; this is the associated
// definition.  This struct contains metadata about the linked list.
typedef struct ll_head {
    uint64_t          num_elements;  //  # elements in the list
    LinkedListNodePtr head;  // head of linked list, or NULL if empty
    LinkedListNodePtr tail;  // tail of linked list, or NULL if empty
} LinkedListHead;


// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode* CreateLinkedListNode(char* key, char *data);

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node);


// ======================================================
// LinkedList: A Doubly-Linked List
// ======================================================

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy and free the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error.
LinkedList CreateLinkedList();

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
int DestroyLinkedList(LinkedList list);


// Returns the number of elements in the linked list.
//
// INPUT: A LinkedList
//
// Returns the number of elements in the list.
unsigned int NumElementsInLinkedList(LinkedList list);

// Adds an element to the head of a LinkedList, with the string
// as the given pointer.
// The customer is responsible for allocating the string.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A pointer to a string for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int InsertLinkedList(LinkedList list, LinkedListNodePtr newNode);
// LinkedList, char*

// Copies the pointer to the payload at the head of a list
// to the provided dataPtr, and removes the head node from the list.
//
// INPUT: A pointer to the LinkedList.
// INPUT: A pointer to a char* that will be updated
//        with the char* at the head of the list.
//
// Returns 0 if the pop was successful; non-zero for failure.
int PopLinkedList(LinkedList list, char** dataPtr);

#endif  // LINKEDLIST_H