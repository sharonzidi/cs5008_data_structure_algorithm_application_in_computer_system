#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <locale.h>
#include "tree.h"
#include "queue.h"

void searchFile(char* dir, TreeNode* node, Queue* queue) {
  
  struct stat s;
  struct dirent **namelist;
  int num_files;
  num_files = scandir(dir, &namelist, 0, alphasort);
  if (num_files < 0) {
    perror("scandir");
    printf("dir: %s\n", dir);
    return;
  } else {
    int i = 0;
    while (i < num_files) {
      // Ignore dotfiles, such as .emacs
      if (namelist[i]->d_name[0] == '.') {
        free(namelist[i]);
        i++;
        continue;
      }
      char *directory;
      int length = strlen(dir) + strlen(namelist[i]->d_name);
      directory = (char*) malloc(((length + 3)*sizeof(char)));
      if (directory == NULL) {
        printf("Couldn't malloc for filecrawler.directory\n");
        return;
      }
      // Copy the path and file name into the "directory" string
      snprintf(directory, length + 3, "%s/%s", dir, namelist[i]->d_name);

      // Use stat() to get info about the given directory (or file)
      if (0 == stat(directory, &s)) {
        TreeNode* treeNode = CreateTreeNode(directory, namelist[i]->d_name);
        AddChild(node, treeNode);

        // Tells us if the given directory/file is a directory or not
        if (S_ISDIR(s.st_mode)) {
          strcat(directory, "/");
          // TODO: Here's where you put the new TreeNode into the queue for further processing
          enqueue(treeNode, queue);
          //searchFile(directory, treeNode, queue);
        }
        // printf("File: %s\n", directory);
        
      } else {
        printf("no stat; %s\n", directory);
      }
      free(namelist[i]);
      i++;
    }
  }
  free(namelist);
}

void buildTree(TreeNode* root) {
  Queue* queue = create();
  TreeNode* curNode = root; 
  while (curNode != NULL)
  {
    searchFile(curNode->path, curNode, queue);
    curNode = dequeue(queue);
  }
  free(queue);
}

int main() {
  char* dir = ".";
  int len = strlen(dir) + 1;
  char* path = malloc(sizeof(char)*len);
  snprintf(path, len, "%s", dir);
  
  TreeNode* rootNode = CreateTreeNode(path, dir);
  //Queue* queue = create();
  buildTree(rootNode);
  //searchFile(dir, rootNode,queue);
  PrintTree(rootNode);
}
