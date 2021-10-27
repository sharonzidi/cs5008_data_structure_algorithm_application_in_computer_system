#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"

int calcLength(LinkedListPtr list, bool debug){
    if(debug) printf("Calculating length for list\n");
    int length = 0;
    if(list == NULL || list->head == NULL) return 0;

    LinkedListNodePtr head = list->head;
    
    while(head != NULL){
        if(debug) printf("Node %d value is %d\n", length + 1, head->data);
        head = head->next;
        length += 1;
    }

    return length;
}

bool testCachedSizeEqualsCalculatedSize(int cached, int calculated){
    return cached == calculated;
}

bool testListSizeDecrementedByTarget(int original, int new, int target){
    return original - new == target;
}

bool validateAppend(LinkedListPtr list, bool debug){
    int preLength = calcLength(list, debug);

    if(debug) printf("The original size of list is %d.\n", preLength);

    bool preSizeMatch = testCachedSizeEqualsCalculatedSize(list->num_elements, preLength);

    if(!preSizeMatch) printf("ERROR: (append_pre) Calculated length does not match num_elements. Expected %d, found %d\n", preLength, list->num_elements);

    if(debug) printf("Testing AppendLinkedList\n");

    int appendRes = AppendLinkedList(list, 100);

    if(debug) printf("Appended 100 to list \n");

    int postLength = calcLength(list, debug);
   
    if(debug) printf("Cached size is %d, Calculated size is %d \n", list->num_elements, postLength);
    
    bool postSizeMatch = testCachedSizeEqualsCalculatedSize(list->num_elements, postLength);

    if(!postSizeMatch) printf("ERROR: (append_post) Calculated length does not match num_elements. Expected %d, found %d\n", postLength, list->num_elements);

    bool wasDecrementedByExpected = testListSizeDecrementedByTarget(postLength, preLength, 1);

    if(!wasDecrementedByExpected) printf("ERROR: Append failed.  Expected length %d, found %d\n", preLength + 1, postLength - preLength);

    if(debug) printf("Validate Append Complete. List currently size %d\n", list->num_elements);
    
    return preSizeMatch && postSizeMatch && wasDecrementedByExpected;
}

bool validateRemove(LinkedListPtr list, bool debug){
    AppendLinkedList(list, 200);
    
    int preLength = calcLength(list, debug);
    
    if(debug) printf("Testing RemoveLLElem, input list is size %d and calculated size is %d. \n", list->num_elements, preLength);

    int res = RemoveLLElem(list, list->head->next);        
        
    int newLength = calcLength(list, debug);

    bool sizeMatch = testCachedSizeEqualsCalculatedSize(list->num_elements, newLength);

    if(!sizeMatch) printf("ERROR: Calculated length does not match num_elements. Expected %d, found %d\n", newLength, list->num_elements);

    bool wasDecrementedByExpected = testListSizeDecrementedByTarget(preLength, newLength, 1);   
    
    if(!wasDecrementedByExpected) printf("ERROR: Remove failed.  Expected length %d, found %d\n", preLength - 1, newLength);
    
    return sizeMatch && wasDecrementedByExpected;
}

void testOperations(LinkedListPtr list, bool debug){
    if(list == NULL) {
        printf("Input list NULL. Nothing to test.\n");
        return;
    }

    bool appendSuccessful = validateAppend(list, debug);
    bool removeSuccessful = validateRemove(list, debug);

    if(!appendSuccessful || !removeSuccessful) printf("TEST(S) FAILED. See console for failure output.\n");
    else printf("TESTS PASSED\n");
}

