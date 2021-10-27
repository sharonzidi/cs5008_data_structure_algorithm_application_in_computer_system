#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define HT_SIZE 15

int hashtable[HT_SIZE]
;
typedef struct node Node;

struct hashtable {
  int num_buckets;
  Node** buckets;// Array of Node*
};
typedef struct hashtable Hashtable; 

struct node {
  char* key;
  int value;
  Node* next;
};

Hashtable* CreateHashtable(int num_buckets) {
  Hashtable* ht = (Hashtable*)malloc(sizeof(Hashtable));
  ht->num_buckets = num_buckets;
  ht->buckets = (Node**)malloc(sizeof(Node*)*num_buckets);
  int i;
  for (i = 0; i < num_buckets; i++) {
    ht->buckets[i] = NULL;
  }
  return ht;
}




int hash(char* key) {
  return strlen(key);
}

//void update(Hashtable, key, value);

void put(Hashtable* ht, char* key, int value) {
  //   ht[hash(key)] = value;
  int which_bucket = hash(key) % ht->num_buckets;
  Node* chain = ht->buckets[which_bucket];
  if (chain == NULL) {
    chain = (Node*)(malloc(sizeof(Node)));
    chain->key = key;
    chain->value = value;
    chain->next = NULL;
    ht->buckets[which_bucket] = chain;
  } else {
    Node* new_elem = (Node*)(malloc(sizeof(Node)));
    new_elem->key = key;
    new_elem->value = value;
    new_elem->next = chain;
    ht->buckets[which_bucket] = new_elem;
  }
  
  
}

int get(Hashtable* ht, char* key) {
  //   return ht[hash(key)];
  int which_bucket = hash(key) % ht->num_buckets;
  Node* node = ht->buckets[which_bucket];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      // HIT!!
      return node->value;
    }
    node = node->next;
  }
  return -1;
}

void PrintHashtable(Hashtable* ht) {
  printf("HT has %d buckets\n", ht->num_buckets);

  int i;
  for (i = 0; i < ht->num_buckets; i++) {
    Node* node = ht->buckets[i];
    printf("Bucket %d: ", i);
    while (node != NULL) {
      printf("key: %s\tvalue:%d ->", node->key, node->value);
      node = node->next;
    }
    printf("\n");
  }
}


int main() {
  Hashtable* hashtable = CreateHashtable(15);
  put(hashtable, "onion", 25);
  put(hashtable, "eggs", 14);
  put(hashtable, "potato", 12);
  put(hashtable, "apple", 42);

  PrintHashtable(hashtable);
  
  printf("A onion is %d\n", get(hashtable, "onion"));

  printf("A potato is %d\n", get(hashtable, "potato"));

  put(hashtable, "onion", 19);
  put(hashtable, "watermelon ice cream", 4); // Bucket 20

  printf("A onion is %d\n", get(hashtable, "onion"));
  
  PrintHashtable(hashtable);
}


