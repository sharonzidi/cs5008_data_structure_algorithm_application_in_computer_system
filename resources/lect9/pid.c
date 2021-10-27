#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t id =  getppid();
  printf("the ppid of this program is %d\n", id);

  pid_t pid = getpid();
  printf("the pid of this program is %d\n", pid);

  int res = fork();
  //  printf("res: %d \n", res);
  if (res < 0){
    // error!!!
  }
  if (res == 0) {
    printf("Child process!!!\n");
    sleep(20);
    printf("child is waking up\n");
    exit(0);
  }

  printf("Parent process!!!\n");


  
  exit(0);
}
