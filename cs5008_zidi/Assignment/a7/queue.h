#include <stdio.h>
#include <stdlib.h>
#ifndef QUEUE_H
#define QUEUE_H
#define SIZE 50
#include "tree.h"

// Defining a queue based on an array.

typedef struct Queue{
  TreeNode* node[SIZE];
  int front;
  int rear;
} Queue;

TreeNode* dequeue(Queue* queue);

void enqueue(TreeNode* node, Queue* queue);

Queue* create();

void destroy(Queue* queue);

#endif
