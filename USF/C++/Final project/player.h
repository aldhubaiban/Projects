#ifndef PLAYER_H
#define PLAYER_H

struct player
{
	int player_balance;
	int player_cards[11];
	int num_of_cards;
	int cards_counter;
	int hand_total;
	int player_bet;
	int split1[11];
	int split2[11];
	int split_condition;

	int split_sum1;
	int split_sum2;

	bool bust;
	bool surrender;
	bool blackjack_;
	bool DoubleDown;

	bool splits1;
	bool split1_bust;
	bool splits2;
	bool split2_bust;
	bool split1_blackjack_;
	bool split2_blackjack_;

};



int cards();

/*Give a rando card from a deck */

void intial_balnce(struct player list[], int num_of_players);

/*intial every player with a $1000 */
 
void bet(struct player list[], int num_of_players);

/*to allow the user to bet a number between 5 to 100 and decrease it from player's balance */

void give_Two_Cards(struct player list[], int num_of_players);

/*Give the first two cards to every player */

void check_bust(struct player list[], int player);

/* check if a player go over 21 (BUST)*/

void hit(struct player list[],int i);

/*allow a player to hit*/

void double_down(struct player list[], int i);

/* a player can get one card and doubles player's bet */

void stand(struct player list[],int i);

/*stand is allow player to hold on to the cards he have !*/

void surrender(struct player list[], int i);

/*return half of the bet to the player */

void Ace(struct player list[], int i);

/*if a player have 1,11 it will change to ACE which is allow the player to have either 1 or 11 depends on the cards total */

void gameoptions(struct player list[],int num_of_players);

/*give a player the game options */

void display_cards(struct player list[], int i);

/*display a cards for the players */

void player_sum(struct player list[],int i);

/*sum the players card to determine winner*/

void split(struct player list[],int i);

/*player allowed to split if the two cards matched*/

void switch_split(struct player list[],int i);

/*game option when a player split*/

void display_cards_split(struct player list[], int i);

/*display a cards for the players */

void check_bust_split(struct player list[], int i);

/* check if a player go over 21 (BUST)*/

void hit_split(struct player list[],int i);

/*allow a player to hit*/

void split_sum(struct player list[],int i);

/*sum the players card to determine winner*/

void stand_split(struct player list[],int i);

/*stand is allow player to hold on to the cards he have !*/

void double_down_split(struct player list[], int i);

/* a player can get one card and doubles player's bet */


#endif