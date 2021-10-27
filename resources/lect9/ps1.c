#include <stdio.h>
#include <stdlib.h>

int main() {
  pid_t pid;

  int x = 1;

  pid = fork();
  if (pid < 0) {
    // Error
  }

  if (pid == 0) {
    printf("child\n");
    exit(0);
  }

  printf("parent\n");
  exit(0);
}
