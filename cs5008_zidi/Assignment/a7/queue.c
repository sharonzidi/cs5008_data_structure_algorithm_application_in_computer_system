#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

// ===============================
// Queue Operation Implementation
// ===============================

TreeNode* dequeue(Queue* queue){
  //  queue->front;
  return (queue->node[queue->front--]);
}

void enqueue(TreeNode* node, Queue* queue){
  if (queue->rear == 0){
    // Queue is full!!!
    printf("Can't add another customer-- the queue is full!");
  }
  else{
    //    queue->rear--;
    queue->node[queue->rear--] = node;
  }
  
}

Queue* create(){
  // Allocate space on the heap
  Queue* newQueue = (Queue*)malloc(sizeof(Queue));
  
  // Initialize anything
  newQueue->front = SIZE-1;
  newQueue->rear = SIZE-1;
  
  // Return pointer to new queue
  return newQueue;
}

void destroy(Queue* queue){
  free(queue);
}
