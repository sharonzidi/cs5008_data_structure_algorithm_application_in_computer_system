#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdint.h>
#include "LinkedList.h"
#include "sort.h"

// int hashtable[HT_SIZE];
struct hashtable {
  int num_buckets;
  int num_elements;
  LinkedList* buckets;
};

typedef struct hashtable *Hashtable; 

// Hashtable Resize(Hashtable ht);

int HashString(char* key);
// Allocates and returns a new Hashtable.
//
// INPUT:
//   numBuckets: The number of buckets this hashtable will start with.
//
// Returns NULL if the hashtable was unable to be malloc'd, or
// the hashtable.
Hashtable CreateHashtable(int num_buckets);

// Destroys and Frees the hashtable.
//
// Input:
//   ht: the table to be free'd. It is unsafe to use the
//    hashtable after this is called.
//   value_free_function: The function to be called to free the
//     values in this hashtable.
void DestroyHashtable(Hashtable ht);

// Puts the given key value pair int the hashtable.
//
// INPUT:
//   ht: the hashtable to insert into
//   kvp: the key-value pair to put into the hashtable.
//   old_kvp: if there is a collision, sets the old_kvp to point at the previous value. 
//
// Returns 0 if put is successful.
// Returns 1 on failure (e.g., no more memory)
// Returns 2 if the key is already in the hashtable
void put(Hashtable ht, char* key, char *value);

// Looks up the given key in the hashtable.
// Returns the Key-Value pair in the provided result pointer.
//
// INPUT:
//   ht: the hashtable to lookup in
//   key: the key to lookup
//   result: If the key is in the hashtable, this is used
//      to return a pointer to a HTKeyValue to the caller.
//      Note, this HTKeyValue is still in the hashtable, so can't
//      be used to free the value.
//
// Returns 0 if the lookup was successful (and the result is valid).
// Returns -1 if the key was not found.
LinkedList LookupInHashtable(Hashtable ht, char* key);

void PrintHashtable(Hashtable ht);

// Replaces the value of a given key in the hashtable.
//
// INPUT:
//   ht: Hashtable to replace value
//   key: key of item to be replaced
//   new_val: new item to put in HT
//   old_val: the HTKeyValue that was removed from the hashtable,
//      which allows the caller to free it as necessary.
//
// Returns 0 if successful (and oldVal is valid)
// Returns -1 if the key was not found in the hashtable (and oldval is invalic)
//int ReplaceInHashtable(Hashtable ht, HTKeyValue new_val, HTKeyValue *old_val);

// Gets the number of elements in the hashtable.
//
// INPUT:
//   ht: the Hashtable
//
// Returns the number of elements in the hashtable.
int NumElemsInHashtable(Hashtable ht);


int HashString(char* key);

// Computes an int from a string, to be used for a key in a HTKeyValue.
//
// INPUT:
//   buffer: a pointer to the array holding the string
//   len: the length of the string
//
// Returns an int to be used as an input to FNVHashInt64 for the hash value.
uint64_t FNVHash64(unsigned char *buffer, unsigned int len);

// Creates a hashed value from a given key.
//
// INPUT:
//   makehash: an int to be hashed for the key of a HTKeyValue pair
//
// Returns the int to be used as a key.
uint64_t FNVHashInt64(uint64_t makehash);


#endif  // HASHTABLE_H