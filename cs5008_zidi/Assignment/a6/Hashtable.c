#include <inttypes.h>
#include "Hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort.h"

//read a string , sort char in string -> num = FNVhash64(new string) -> FNVhashInt64(num)

Hashtable CreateHashtable(int num_buckets)
{
  Hashtable ht = (Hashtable)(malloc(sizeof(struct hashtable)));
  ht->num_buckets = num_buckets;
  ht->num_elements = 0;
  ht->buckets = (LinkedList*)malloc(sizeof(LinkedList) * num_buckets);
  int i; 
  for (i = 0; i < num_buckets; i++)
  {
    //ht->buckets[i] = CreateLinkedList();
    ht->buckets[i] = NULL;
  }
  return ht;
}

// Hashtable Resize(Hashtable ht)
// {
//   Hashtable newht = CreateHashtable(ht->num_buckets * 9);
//   int i;
//   for (i = 0; i < ht->num_buckets; i++)
//   {

//     LinkedList list = ht->buckets[i];
//     LinkedListNodePtr headNode = list->head;

//     while (headNode != NULL)
//     {
//       put(newht, headNode->key, headNode->value);

//       headNode = headNode->next;
//     }
//   }
//   return newht;
// }

void put(Hashtable ht, char *key, char *value)
{
  char* keyCopy = (char*)malloc(strlen(key)+1);
  strncpy(keyCopy, key, strlen(key)+1);

  char* valCopy = (char*)malloc(strlen(value)+1);
  strncpy(valCopy, value, strlen(value)+1);

  int makehash = FNVHash64((unsigned char *)keyCopy, strlen(keyCopy));
  int idx = FNVHashInt64(makehash);
  idx = idx < 0 ? -idx : idx;

  int which_bucket = idx % ht->num_buckets;

  if (ht->buckets[which_bucket] == NULL)
    ht->buckets[which_bucket] = CreateLinkedList();

  LinkedList chain = ht->buckets[which_bucket];
  LinkedListNodePtr newNode = CreateLinkedListNode(keyCopy, valCopy);
  LinkedListNodePtr curNode = chain->head;

  while (curNode != NULL)
  {
    if (strcmp(curNode->key, keyCopy) == 0)
    {
      InsertLinkedList(curNode->data, newNode);
      return;
    }
    curNode = curNode->next;
  }

  LinkedListNodePtr head_chain = CreateLinkedListNode(keyCopy, NULL);
  InsertLinkedList(chain, head_chain);
  InsertLinkedList(head_chain->data, newNode);
}


LinkedList LookupInHashtable(Hashtable ht, char *key)
{

  int makehash = FNVHash64((unsigned char *)key, strlen(key));
  int idx = FNVHashInt64(makehash);
  idx = idx < 0 ? -idx : idx;
  int which_bucket = idx % ht->num_buckets;

  LinkedList chain = ht->buckets[which_bucket];
  if (chain == NULL) return NULL;

  LinkedListNodePtr curNode = chain->head;

  while (curNode != NULL)
  {
    if (strcmp(curNode->key, key) == 0)
    {
      return curNode->data;
    }
    curNode = curNode->next;
  }
  return NULL;
}


void PrintHashtable(Hashtable ht)
{
  //printf("HT has %d buckets\n", ht->num_buckets);
  int i;
  for (i = 0; i < ht->num_buckets; i++)
  {
    LinkedList list = ht->buckets[i];
    if (list == NULL) continue;
    LinkedListNodePtr headNode = list->head;
    //printf("Bucket %d: ", i);
    while (headNode != NULL)
    {
      printf("%s :", headNode->key);
      LinkedListNodePtr dataNode = headNode->data->head;
      while (dataNode != NULL) {
        printf(" %s", dataNode->value);
        dataNode = dataNode->next;
      }
      printf("\n");
      headNode = headNode->next;
    }
    //printf("\n");
  }

  for (i = 0; i < ht->num_buckets; i++)
  {
    LinkedList list = ht->buckets[i];
    if (list == NULL) continue;
    LinkedListNodePtr headNode = list->head;
    int keyCnt = 0;
    while (headNode != NULL) {
      headNode = headNode->next;
      keyCnt += 1;
    }
    keyCnt == list->num_elements
    printf("collison with bucket id %d : %d\n", i, keyCnt);
  }

}

int NumElemsInHashtable(Hashtable ht)
{
  return ht->num_elements;
}

int HashString(char *key)
{
  return strlen(key);
}

uint64_t FNVHash64(unsigned char *buffer, unsigned int len)
{
  static const uint64_t FNV1_64_INIT = 0xcbf29ce484222325ULL;
  static const uint64_t FNV_64_PRIME = 0x100000001b3ULL;
  unsigned char *bp = (unsigned char *)buffer;
  unsigned char *be = bp + len;
  uint64_t hval = FNV1_64_INIT;
  /*
   * FNV-1a hash each octet of the buffer
   */
  while (bp < be)
  {
    /* xor the bottom with the current octet */
    hval ^= (uint64_t)*bp++;
    /* multiply by the 64 bit FNV magic prime mod 2^64 */
    hval *= FNV_64_PRIME;
  }
  /* return our new hash value */
  return hval;
}

uint64_t FNVHashInt64(uint64_t makehash)
{
  unsigned char buf[8];
  int i;
  for (i = 0; i < 8; i++)
  {
    buf[i] = (unsigned char)(makehash & 0x00000000000000FFULL);
    makehash >>= 8;
  }
  return FNVHash64(buf, 8);
}
