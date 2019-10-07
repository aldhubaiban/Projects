#ifndef DEALER_H
#define DEALER_H

#include "player.h"

#include <iostream>
#include <string>

using namespace std;

struct Dealer
{
	int dealer_cards[11];
	int counter;
	int sum_cards;

	bool bust;
};


void dealer_hit(struct Dealer list[]);
/*Dealer allowed to hit up to 17 then it will stop*/

void give_dealer_card(struct Dealer dealer[]);
/*give the dealer one card*/
void dealer_ace(struct Dealer list[]);
/*Ace function to determine one or 11*/

void dealer_sum(struct Dealer list_dealer[]);
/*sum the dealers card to determine winner */
void dealer_display(struct Dealer list[]);
/*Dealer display cards*/

void determine_winner(struct player list[], int num_of_players, struct Dealer list_dealer[]);
/*it will check all cases to determine winner */

void reset_variables(struct player list[],struct Dealer list_dealer[], int num_of_players);
/*reset all the variables for a new round */

void determine_winner_split(struct player list[],struct Dealer list_dealer[],int i);
/*it will check all cases to determine winner for split */



// project requirements


//Use vector 
void vector_stars();


//All classes have constructor and destructor
//Use operator overloading
//Use const 
class Output
{

friend ostream& operator<<(ostream&,const Output&);

public:
	//constructor 
	Output(string num):welcome(num)	{}
	//destructor
	virtual ~Output(void){}

	virtual void Greating(void)
	{
		cout<<"Unkown Game"<<welcome<<endl;
	}

protected:
	string welcome;
private:
	string ask;
};


//Use inheritance
class Black_Jack: public Output
{
public:
	//constructor 
	Black_Jack(string game, string num):Output(num),game_type(game){}

	//destructor
	~Black_Jack(void){}

virtual void Greating(void)
{
	cout<<"Welcome to"<<game_type<<welcome<<endl;
}


protected:
	string game_type;
};






#endif //DEALER_H