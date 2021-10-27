#include <stdio.h>

#include "user.h"
/*
void StandardGreeting(User*);
void FormalGreeting(User*);
void InformalGoodbye(User*);
void FormalGoodbye(User*);
*/

int main() {

  User user = {"Big", "Lebowski", 42};
  StandardGreeting(&user);
  FormalGreeting(&user);
  InformalGoodbye(&user);
  FormalGoodbye(&user);

  return 0;
}


