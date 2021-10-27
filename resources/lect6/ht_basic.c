#include <stdio.h>
#include <string.h>

#define HT_SIZE 15

int hashtable[HT_SIZE];

int hash(char* key) {
  return strlen(key);
}

void put(int* ht, char* key, int value) {
  ht[hash(key)] = value;
}

int get(int* ht, char* key) {
  return ht[hash(key)];
}




int main() {
  put(hashtable, "onion", 25);
  put(hashtable, "eggs", 14);
  put(hashtable, "potato", 12);
  put(hashtable, "apple", 42);
  
  printf("A onion is %d\n", get(hashtable, "onion"));

  printf("A potato is %d\n", get(hashtable, "potato"));

  
  
}


