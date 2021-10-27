#include <stdio.h>

struct card {
    char* suit;
    char* value;
};

typedef struct card Card;

//// Class Exercise ////
// This code is incomplete and is not the *best* example of how to represent this data.
// Can you think of a better way? 
int * countSuits(Card* cards, int length) {
    static int return_value[4] = {0,0,0,0};
    //Heart == 0
    //Spade == 1
    //Diamond == 2
    //Club == 3

    int i;

    for(i=0; i<length; i++){
        Card current = cards[i];
        char* suit = current.suit;

        if(suit == "Heart") {
           return_value[0]++;
        }

        if(suit == "Spade"){
	   return_value[1]++; 
        }

        if(suit == "Diamond"){
	   return_value[2]++;
	}

	if(suit == "Club"){
	   return_value[3]++;
	}
    }

    return return_value;
}

void printCard(Card* the_card) {
    printf("The suit of the card is %s\n", (*the_card).suit); // the * must be inside the paren to deference
}

void changeSuit(Card* the_card, char* new_suit){

    printf("The location of the card is [%p]\n", the_card);
    the_card->suit = new_suit; // the arrow operator can be used to 'get' members from a value referenced by a pointer
}

int main() {
    //Define a set of functions which can print out playing card details
    Card card_one;

    card_one.suit = "Spade";
    card_one.value = "King"; 
    printCard(&card_one); // use the & to fetch the memory address of a value (ie the pointer)

    //printf("The suit of the card is %s \n", card_one);
  
    //card_one.suit = "Heart";
    //printf("The location is the card is [%s]\n", (*card_one).value);
    changeSuit(&card_one, "Heart");
    printCard(&card_one);
    
    Card cards[] = {card_one};
    int* res = countSuits(cards, 1);
    printf("%d\n", res[0]);
   
//printf("The suit of the card is %s\n", card_one);
   
}
