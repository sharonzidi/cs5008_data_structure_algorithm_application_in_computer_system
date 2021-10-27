#include <stdio.h>
#include <unistd.h>


int main() {
  char* myargv[16];
  myargv[0] = "/bin/ls";
  myargv[1] = "-l";
  myargv[2] = NULL; // required for exec

  int pid = fork();
  
  if (pid == 0) { // In the child
    printf("going to launch ls\n");
    execve(myargv[0], myargv, NULL);
    printf("Arrgggh!! terminated abnormally\n");
    exit(1);
  } else {
    wait(NULL); // waits for all child processes
  }
  printf("parent says good night\n");
}
