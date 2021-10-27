#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TreeNode* CreateTreeNode(char* path, char* name) {
  TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
  int len = strlen(name) + 1;
  newNode->name = malloc(len);
  snprintf(newNode->name, len, "%s", name);

  newNode->path = path;
  newNode->children = NULL;
  newNode->siblings = NULL;
  newNode->level = 0;
  return newNode;
}

void AddChild(TreeNode* root, TreeNode* child) {
  
  if (root->children == NULL)
  {
    child->level = root->level + 1;
    root->children = child;
  }
  else
  {
    child->siblings = root->children->siblings;
    root->children->siblings = child;
    child->level = root->children->level;
  }
}

void DestroyTreeNode(TreeNode* node) {
  if (node == NULL)
    return;
  DestroyTreeNode(node->children);
  DestroyTreeNode(node->siblings);
  free(node->name);
  free(node->path);
  free(node);
}


void PrintTree(TreeNode* node) {
  if (node == NULL)
    return;
    for (int i = 0; i < node->level; i++)
    {
      printf("  ");
    }
  printf("%s\n", node->name);
  PrintTree(node->children);
  PrintTree(node->siblings);
}