#include<stdio.h>
#include<stdbool.h>

typedef struct node Node;

struct node {
    char* data;
    Node* next;
};

struct doubly {
    char* data;
    Node* prev;
    Node* next;
};

typedef struct list List;

struct list {
    Node* head;
};

void addFront(List* list, Node* node) {
    Node* head = list->head;

    (*node).next = head;
    (*list).head = node;
}

void removeAt(List* list, int index) {
    Node* current = list->head;
    
    if(index == 0){
        (*list).head = current->next;
        return;
    }

    Node* prev = current;
    current = current->next;

    int i = 1;
    while(i != index) {
        current = current->next;
        prev = prev->next;
        i++;
    }
    
    prev->next = current->next;
}

void printNodes(List* list) {
    Node* current = list->head;
    
    //bool flag = true;

    while(current != NULL) {
        printf("The value is %s \n", current->data);
        current = current->next;
    }
    /*
    while(flag) { //node.next does not exist
        printf("The value in while is %s \n", (*current).data); //node.data does not exist
        
        if((*current).next != NULL){
            current = (*current).next; // current.next does not exist
        } else {
            flag = false;
        }
    }*/
}

void swapRight(List* list, Node* node){
    Node* curr = list->head;

    if(node->data == curr->data){
        Node* temp = curr->next;
        curr->next = curr->next->next;
        temp->next = curr;
        list->head = temp;
    }

    int i = 1;
    Node* prev = curr;
    curr = curr->next;

    while(curr->data != node->data){
        prev = prev->next;
        curr = curr->next;
        i++;
    }

    if(curr->next == NULL) return;

    Node* temp = curr->next;
    curr->next = curr->next->next;
    temp->next = curr;
    prev->next = temp;
}


int main(){
    
    Node n1 = {"n1", NULL};
    
    //printf("Value is %s \n", n1.data);

    //printNodes(&n1); //need to pass a pointer
    

    Node n2 = {"n2", NULL};

    n1.next = &n2;
    List l1 = {&n1};
    
    Node n3 = {"n3", NULL};
    addFront(&l1, &n3);
    Node n4 = {"n4", NULL};
    addFront(&l1, &n4);
   
    printNodes(&l1);

    printf("after \n");

    removeAt(&l1, 1);
    
    swapRight(&l1, &n1);

    printNodes(&l1);
    //printNodesRec(&n1);
    return 0;
}
