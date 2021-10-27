#include <stdio.h>

struct user_info {
  char *first_name;
  char *last_name;
  int id;
};

typedef struct user_info User;


void StandardGreeting(User *user) {
  printf("Hello, %s!\n", user->first_name);
}

void FormalGreeting(User *user) {
  printf("Greetings, ID: %d\n", user->id);
  printf("Name: %s, %s\n", user->last_name, user->first_name);
}

void InformalGoodbye(User *user) {
  printf("See ya later %s!\n", user->first_name);
}

void FormalGoodbye(User *user) {
  printf("Good bye, ID: %d\n", user->id);
  printf("%s, %s\n", user->last_name, user->first_name);
}

int main() {

  User user = {"Big", "Lebowski", 42};
  StandardGreeting(&user);
  FormalGreeting(&user);
  InformalGoodbye(&user);
  FormalGoodbye(&user);

  return 0;
}
