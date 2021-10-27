#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
  char *data;
  Node *leftChild;
  Node *rightChild;
  Node *parent;
  int visited;
};

struct binaryTree
{
  Node *root;
};

typedef struct binaryTree BinaryTree;
#define kStackSize 50;
int stack_head = 0;
Node *stack[50];

Node *CreateNode(char *data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  newNode->leftChild = NULL;
  newNode->rightChild = NULL;
  newNode->parent = NULL;
  newNode->visited = 0;
  return newNode;
}

void DestroyNode(Node *node)
{
  if (node == NULL)
    return;

  destroyNode(node->leftChild);
  destroyNode(node->rightChild);
  //  destroyNode(node->parent);

  // Destroy node
  free(node);
}

// 1 to add the node as a left child;
// 0 to add the node as a right child.
void AddChild(Node *node, Node *child, int leftChild)
{
  if (leftChild)
  {
    node->leftChild = child;
  }
  else
  {
    node->rightChild = child;
  }
  child->parent = node;
}

void *Push(Node *node)
{
  if (stack_head < 50)
  {
    stack[stack_head++] = node;
  }
  //  return s; // No more call by value, so not returning.
}

Node *Pop()
{
  if (stack_head > 0)
  {
    stack_head = stack_head - 1;
    return stack[stack_head];
  }
  return NULL; // sentinel value
}

void PrintTree_dfs_iter(Node *root)
{
  Push(root);
  Node *cur_node = pop();

  while (cur_node != NULL)
  {
    printf("%s: ", cur_node->data);
    Enqueue(cur_node->leftChild);
    Enqueue(cur_node->rightChild);
    cur_node = Dequeue();
  }
}

void PrintTree_bfs(Node *root)
{
  Push(root);
  Node *cur_node = pop();

  while (cur_node != NULL)
  {
    printf("%s: ", cur_node->data);
    Push(cur_node->rightChild);
    Push(cur_node->leftChild);
    cur_node = Pop();
  }
}

void PrintTreeDfsPost(Node *root)
{
  Node *stack[20];
  int head = 0;

  stack[head++] = root;

  while (head > 0)
  {
    // Take the node out
    Node *node = stack[--head];
    // Print the value
    printf("%s\n", node->data);
    // Put the children in
    if (node->rightChild != NULL)
    {
      stack[head++] = node->rightChild;
    }
    if (node->leftChild != NULL)
    {
      stack[head++] = node->leftChild;
    }
  }
}

void printTreeDfsPost_stack(Node *root)
{
  Node *stack[20];
  int top = 0;

  stack[top++] = root;

  while (top > 0)
  {
    Node *node = stack[top - 1];
    if (node->visited == 0)
    {
      Node *node = stack[--top];
      printf("%s\n", node->data);
      node->visited = 1;
    }
    else
    {
      if (node->rightChild != NULL)
      {
        stack[top++] = node->rightChild;
      }
      if (node->leftChild != NULL)
      {
        stack[top++] = node->leftChild;
      }
    }
  }
}

void PrintTreeDfs(Node *root)
{
  Node *stack[20];
  int head = 0;

  stack[head++] = root;

  while (head > 0)
  {
    // Take the node out
    Node *node = stack[--head];
    // Print the value
    printf("%s\n", node->data);
    // Put the children in
    if (node->rightChild != NULL)
    {
      stack[head++] = node->rightChild;
    }
    if (node->leftChild != NULL)
    {
      stack[head++] = node->leftChild;
    }
  }
}

void PrintTreeBfs(Node *root)
{
  Node *queue[20];
  int head = 0;
  int tail = 0;

  queue[tail++] = root;
  while (head < tail)
  {
    // Take the node out
    Node *node = queue[head++];

    // Print the value
    printf("%s\n", node->data);

    // Put the children in
    if (node->leftChild != NULL)
    {
      queue[tail++] = node->leftChild;
    }
    if (node->rightChild != NULL)
    {
      queue[tail++] = node->rightChild;
    }
  }
}

void PrintTree(Node *root, int depth)
{
  if (root == NULL)
    return;
  // Print node
  int i = 0;
  for (i = 0; i < depth - 1; i++)
  {
    printf("\t");
  }
  printf("|-----> ");
  printf("%s\n", root->data);
  // Print left
  PrintTree(root->leftChild, depth + 1);

  // Print right
  PrintTree(root->rightChild, depth + 1);
}

int main()
{

  Node *root = CreateTree();
  root->data = "root";
  Node *n1 = CreateNode("N1");
  Node *n2 = CreateNode("N2");
  Node *n3 = CreateNode("N3");
  Node *n4 = CreateNode("N4");
  Node *n5 = CreateNode("N5");
  Node *n6 = CreateNode("N6");

  n1->leftChild = n3;
  n1->rightChild = n4;
  n4->leftChild = n5;
  n4->rightChild = n6;
  root->rightChild = n2;
  root->leftChild = n1;

  PrintTree(root, 0);

  printf("\n\n");

  PrintTreeDfs(root);

  PrintTreeBfs(root);

  printf("\n\n");
  printTreeDfsPost_stack(root);
}