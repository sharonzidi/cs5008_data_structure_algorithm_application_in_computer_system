#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HT_SIZE 10

// Requirement: We need a way to determine (efficiently) the age of a ninja turtle.
// For example: Given 'Leo', return his age of 36.
int hashtable[HT_SIZE];

int hash(char* data){
    return strlen(data);
}

void put(int* table, char* key, int value){
    table[hash(key)] = value;
}

int get(int* table, char* key){
    return table[hash(key)];
}

int main(){
    char* leo = "leo";
    //int index = hash(leo);
    //printf("index is %d\n", index);

    put(hashtable, leo, 36);   
    
    char* ralph = "ralph";
    char* donny = "donny";

    //int rIndex = hash(ralph);
    //printf("rIndex is %d\n", rIndex);

    //int dIndex = hash(donny);
    
    put(hashtable, ralph, 35);
    //printf("index %d is %s\n", rIndex, get(hashtable, rIndex));

    put(hashtable, donny, 33);
    //printf("index %d is %s\n", rIndex, get(hashtable, rIndex));

    //printf("hashtable value is %s\n", hashtable[index]);
    
    int leoAge = get(hashtable, leo);

    printf("Leo is %d years old\n", leoAge);

    return 0;
}
