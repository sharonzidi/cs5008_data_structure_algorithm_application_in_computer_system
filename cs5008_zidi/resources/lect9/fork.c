#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main() {
  pid_t pid[5];
  int i; 
  int child_status = 42; 

  //  printf("child_status: %d \n", child_status);

  // Create child processes
  for (i = 0; i < 5; i++) {
    pid[i] = fork();
    //    
    sleep(1);
    if (pid[i] == 0) {
      //  printf("Hi from child %d\n", i);
      while(1);
      //      exit(100 + i);
    }
    printf("pid[i] = %d\n", pid[i]);
  }

  for (i = 0; i < 5; i++) {
    printf("Killing process: %d (child %d)\n", pid[i], i);
    kill(pid[i], SIGINT);
  }

  // Wait for child processes
  for (i = 0; i < 5; i++) {
    pid_t wpid = waitpid(pid[i], &child_status, 0);
    printf("child status for child %d: %d\n", i, child_status);
    sleep(1);

    if (WIFEXITED(child_status)) {
      printf("child %d terminated with exit status %d\n", wpid, WEXITSTATUS(child_status));
    } else {
      printf("child %d terminated abnormally\n", wpid);
    }
  }

  /*
  if (fork() == 0) { // Child process
    printf("child_status (in child): %d \n", child_status);
    printf("HC: hello from child\n");
    exit(0);
  }

  // Parent.
  printf("HP: Hello from parent\n");

  wait(&child_status);  // blocking call
  
  printf("child_status: %d \n", child_status);
  */
  printf("Bye!\n"); 
  
  exit(0);
}
