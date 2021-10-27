#include <stdio.h>

typedef struct node Node;

struct node {
  char* data;
  Node* prevNode;
  Node* nextNode;
};

struct list {
  Node* head;
};

typedef struct list List;

List* CreateList() {

}

Node* CreateNode(char* data) {

}




void InsertNode(List* list, Node* node) {
  // TODO: Check that node isn't NULL
  if (list->head != NULL) {
    list->head->prevNode = node; // Points head of list to new node. 
    node->nextNode = list->head; // New node now points at the old head
    list->head = node;
  } else {
    list->head = node;
  }
}
void Delete(List* list, Node* node) {
  node->prevNode->nextNode = node->nextNode;
  node->nextNode->prevNode = node->prevNode;
}

void PrintList(List* list) {
  Node* curNode = list->head;
  while (curNode != NULL) {
    // Print node
    printf("%s\n", curNode->data);
    curNode = curNode->nextNode;
  }
}

int main() {
  Node n1 = {"n1", NULL, NULL}; // CreateNode()
  Node n2 = {"n2", NULL, NULL};
  Node n3 = {"n3", NULL, NULL};

  List list = {NULL};

  /*
  n1.nextNode = &n2;
  n2.prevNode = &n1;
  n2.nextNode = &n3;
  n3.prevNode = &n2;
  */
  InsertNode(&list, &n3);
  PrintList(&list);
  
  InsertNode(&list, &n2);
  InsertNode(&list, &n1);
  
  PrintList(&list);

  Node n4 = {"n4", NULL, NULL};
  /*
  list.head->prevNode = &n4; // Points head of list to new node. 
  n4.nextNode = &n1; // New node now points at the old head
  list.head = &n4;
  */

  InsertNode(&list, &n4);   
  printf("\n\n");

  PrintList(&list);


  Delete(&list, &n2);

  PrintList(&list);
}