#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#define MAXARGS 5
#define MAXLINE 8192

// TODO: Put your command names here
char* commands = {"cd", "help", "..."};

// TODO: Put your command function pointers here
void* command_functions = {cd, help};

void* cd(char* input) {
  // TODO: Implement cd
  
}

/***
 **  Wrapper of fork(). Checks for fork errors, quits on error. 
 **/
pid_t Fork(void) {
  pid_t pid;  
  if ((pid = fork()) < 0) {
    fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
    exit(0);
  }
  return pid;
}

/***
 **  Wrapper of fgets. Checks and quits on Unix error. 
 **/
char* Fgets(char *ptr, int n, FILE *stream) {
  char *rptr;
  if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
  return rptr;
}

// Is the command one built into the shell?
// That is, that the *shell* has implemented?
// If so, execute it here
int builtin_command(char** argv) {
  // Loop through
  int res = strcmp(command[i], argv[0]);
 
  if (res == 0) {
    // call the right function.
    command_function[i](argv[1]); // some argument
  }
}



void eval(char *cmdline) {
  char *argv[MAXARGS]; /* Argument list execve() */
  char buf[MAXLINE]; /* Holds modified command line */
  pid_t pid; /* Process id */

  strcpy(buf, cmdline);
  // Split buf into args
  
  if (argv[0] == NULL)
    return; /* Ignore empty lines */

  if (!builtin_command(argv)) {
    // Check that the command/program exists in Unix (ie /bin/) OR (see below) 
    // Create a child process 
    // Run the program/command (execve...)-- what is the result of exec if the command is bogus?

    int res = execve(""); // see run_ls.c for an example
    if (res < 0) {
      //print error message
    }
  } else {
    // What do we do if it *IS* a command built into the shell?
    
  }


  // TODO: Be sure to wait for the child process to terminate
  
  return;
}

int main() {
  char cmdline[MAXLINE]; /* command line buffer */
  while (1) {
    // Print command prompt
    printf("> ");
    // Read input from user
    Fgets(cmdline, MAXLINE, stdin);
    // If we get the eof, quit the program/shell
    if (feof(stdin))
      exit(0);

    // Otherwise, evaluate the input and execute. 
    eval(cmdline);
  }
}
