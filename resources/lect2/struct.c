#include <stdio.h>


struct card {
  char* face; // char[15]
  char* suit; // char[]
};

typedef struct card Card;

void PrintCard(struct card myCard) {
  printf("%s of %s\n", myCard.face, myCard.suit);
}

void ChangeFace(Card* someCard, char* newFace) {
  printf("someCard is at %p\n", someCard);
  //  someCard->face = newFace; // someCard.face = *newFace;
  (*someCard).face = newFace; // someCard.face = *newFace;
  PrintCard(*someCard);
}

int main() {
  const char* ACE = "Ace";
  const char* KING = "King";

  printf("ace: \t%p\n", &ACE);
  printf("king: \t%p\n", &KING);

  
  struct card ace_hearts = {"Ace", "Hearts"};
  printf("ace_hearts: %p\n", &ace_hearts);
  //  ace_hearts.face = "Ace";
  //  ace_hearts.suit = "Hearts";

  const struct card king_hearts = ace_hearts;
  printf("king_hearts: %p\n", &king_hearts); 
  PrintCard(king_hearts);
  
    
  ChangeFace(&king_hearts, "QUEEN");
  king_hearts.suit = "Diamonds";  
  
  /*
  printf("king: %p\n", &king_hearts);
  printf("ace_hearts is at %p\n", &ace_hearts);
  PrintCard(ace_hearts);

  ChangeFace(&ace_hearts, "Jack"); // "Jack" immutable
  */
  PrintCard(king_hearts);

  
}
