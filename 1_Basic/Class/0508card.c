#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(){
  int in_hand[NUM_SUITS][NUM_RANKS] = {0};
  int num_cards, rank, suit;
  char rank_code[] = {'2', '3', '4', '5', '6', '7', '8',
                        '9', 'T', 'J', 'Q', 'K', 'A'};
  char suit_code[] = {'c', 'd', 'h', 's'};
  srand((unsigned) time(NULL));
  printf("enter number of cards in your hand : ");
  scanf("%d", &num_cards);

  printf("Your hand : ");
  while(num_cards > 0){
    suit = rand() % NUM_SUITS;
    rank = rand() % NUM_RANKS;
    if(in_hand[suit][rank] == 0){
      in_hand[suit][rank] ++;
      printf("%c%c ", rank_code[rank], suit_code[suit]);
      num_cards --;
    }
  }
  printf("\n");
  return 0;
}
