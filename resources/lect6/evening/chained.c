#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HT_SIZE 10

int hashtable[HT_SIZE];

int hash(char* data){
    int size = strlen(data);
    return size > HT_SIZE ? size % HT_SIZE : size; //this is called a ternary expression
}

typedef struct node Node;

struct node {
    char* data;
    int value;
    Node* next;
};

typedef struct hashtable HT;

struct hashtable {
    int* bucket_count;
    Node** buckets;
};

void put(HT*table, Node* node, int index){
    Node** buckets = table->buckets;

    if(buckets[index] == NULL){
        buckets[index] = node;
        *(table->bucket_count) = *(table->bucket_count) + 1;
        printf("value is %d\n", (*table->bucket_count));
    } else {
        Node* head = buckets[index];
        node->next = head;
        buckets[index] = node;
    }
}

Node* get(HT* table, Node* node){
    int index = hash(node->data);

    Node* head = table->buckets[index];

    if(head == NULL) return NULL;

    while(head != NULL){
        if(head->data == node->data) return head;
        head = head->next;
    }

    return NULL;
}

void clearBuckets(Node** buckets, int size){
    int i=0;
    for(i=0; i<size; i++)buckets[i] = NULL; // do this to clear out the buckets of stale data
}

int main(){
    Node n1 = {"leo", 36, NULL};
    
    HT* table = (HT*)malloc(sizeof(HT));
    int* count = (int*)malloc(sizeof(int));
    
    (*count) = 0;
    table->bucket_count = count;
    
    Node** buckets = (Node**)malloc(sizeof(Node*) + HT_SIZE);
    clearBuckets(buckets, HT_SIZE);

    table->buckets = buckets;

    printf("The size of table buckets is %d\n", table->bucket_count);

    put(table, &n1, hash(n1.data));

    int index = hash(n1.data);

    Node* leo = table->buckets[index];

    printf("Leo's age is %d\n", leo->value);
    printf("Bucket count is %d\n", *table->bucket_count);
    
    Node n2 = {"ralph", 33, NULL};
    Node n3 = {"donny", 34, NULL};

    put(table, &n2, hash(n2.data));
    put(table, &n3, hash(n3.data));

    int rIndex = hash(n2.data);

    Node* ralphNode = table->buckets[rIndex];

    printf("RalphNode name is %s\n", ralphNode->next->data); 
    
    Node* newLeo = get(table, &n1);
    printf("The new Leo age is %d\n", newLeo->value);
    
    Node n4 = {"Micheoangelo", 50, NULL};

    printf("overflow size is %d\n", hash("jfklasjfklasdjfklasdjfkdsf"));
    return 0;
}
