#include <stdio.h>
#include <stdlib.h>
#ifndef TREE_H
#define TREE_H

typedef struct treeNode
{
    char* path; // The directory this file is in, such as "~/Spr2021/resources/a7/"
    char* name; // The name of this file, such as "tree.c"
    struct treeNode* children; // Essentially a linked list of children
    struct treeNode* siblings; // Essentially a linked list of siblings
    int level; // How deep in the tree this node is
} TreeNode;


TreeNode* CreateTreeNode(char* path, char* name);

void AddChild(TreeNode* root, TreeNode* child);

void DestroyTreeNode(TreeNode* node);

void PrintTree(TreeNode* node);

#endif