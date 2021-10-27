#include <stdio.h>
#include <stdlib.h>


typedef struct node Node;

struct node {
  char* data; // THIS IS A STRING
  Node* prevNode;
  Node* nextNode;
};

struct list {
  Node* head;
};

typedef struct list List;

List* CreateList() {
  List* list = (List*)malloc(sizeof(List));
  list->head = NULL;
  return list;
}

Node* CreateNode(char* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node ->data = data;
  node->prevNode = NULL;
  node->nextNode= NULL;
  return node;
}


void DestroyNode(Node* n) {
  printf("destroying node: %s\n", n->data);
  free(n);
}

void DestroyList(List* list) {
  Node* curNode = list->head;
  Node* nextNode = curNode->nextNode;
  while (curNode != NULL) {
    DestroyNode(curNode);
    curNode = nextNode;
    // Check that curNode is not NULL 
    if (curNode != NULL) {
      nextNode = curNode->nextNode;
    }
    
  }
  free(list);
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
    printf("%p\t%s:%p\t%p\n", curNode->prevNode,
           curNode->data,
           curNode,
           curNode->nextNode);
    curNode = curNode->nextNode;
  }
}
void Swap(Node* n1, Node* n2) {
  n2->prevNode = n1->prevNode;
  n1->prevNode->nextNode = n2;
  n1->prevNode = n2;
  n1->nextNode = n2->nextNode;
  n2->nextNode = n1;
}




/*
List BuildMyList() {
  List list = CreateList();
  Node n1 = CreateNode("n1");
  Node n2 = CreateNode("n2");
  Node n3 = CreateNode("n3");
  
  InsertNode(&list, &n3);
  InsertNode(&list, &n2);
  InsertNode(&list, &n1);
  PrintList(&list);
  printf("\n\n");
  return list;
  }*/

int main() {
  /*  Node n1 = {"n1", NULL, NULL}; // CreateNode()
  Node n2 = {"n2", NULL, NULL};
  Node n3 = {"n3", NULL, NULL};

  List list = {NULL};
  */
  //  List list1 = BuildMyList();
  //PrintList(&list1);

  printf("\n\n");


  List *list = CreateList();
  Node* n1 = CreateNode("n1");
  Node* n2 = CreateNode("n2");
  Node* n3 = CreateNode("n3");
  
  /*
  n1.nextNode = &n2;
  n2.prevNode = &n1;

  n2.nextNode = &n3;
  n3.prevNode = &n2;
  */
  InsertNode(list, n3);  
  InsertNode(list, n2);
  InsertNode(list, n1);
  
  PrintList(list);

  Swap(n2, n3);

  printf("\n\n");
  PrintList(list);


  printf("\n\n");

  DestroyList(list);
  
  /*
  Node n4 = {"n4", NULL, NULL};
  /*
  list.head->prevNode = &n4; // Points head of list to new node. 
  n4.nextNode = &n1; // New node now points at the old head
  list.head = &n4;
  */
  /*
  InsertNode(&list, &n4);   
  printf("\n\n");

  PrintList(&list);


  Delete(&list, &n2);

  PrintList(&list);
  */
}
