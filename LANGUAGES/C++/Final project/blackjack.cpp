
#include "dealer.h"
#include "player.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
using namespace std;




int main()
{

	struct player players[5];
	struct Dealer dealer[1];

	srand(time(NULL));
	int num_of_players;
	string round;

	// use static 
	static int five=5;

	cout<<endl;
	// use vector 
	vector_stars();

	// class inhertence used 
	Output* Great= new Black_Jack(" Black ","Jack");
	Great->Greating();
	delete Great;

	vector_stars();
	cout<<endl;


	cout <<"----- \nHow many players are playing\n-----  \n *NOTE:Max 5 players"<<endl;
	cout<<" ";
	cin>>num_of_players;

	// while loop to limit the players between 1-5 
	while (num_of_players<=0 || num_of_players>five)
	{
		cout<<"invalid number of players"<<endl;
		cout<<"please enter a number between 1 to 5"<<endl;
		cin>>num_of_players;
	}
	// a variable to store the number of players are playing...
	int number_of_players= num_of_players;

	// give a player intial $1000
	intial_balnce(players,number_of_players);
	do{
		// to reset variables when play another round 
		reset_variables(players,dealer,number_of_players);

		// allow player to bet
		bet(players,number_of_players);

		// give players the intial two cards
		give_Two_Cards(players,number_of_players);
		  
		// give a dealer card and hidden card
		give_dealer_card(dealer);
		// show a game option for players
		gameoptions(players,number_of_players);
		// dealers hit after players 
		dealer_hit(dealer);
		// display dealer cards
		dealer_display(dealer);
		// determine winner 
		determine_winner(players,num_of_players,dealer);

		// a condition to insure user will enter yes or no 
		while(1)
		{
			cout<<"would you like to play another round?"<<endl;
			cout<<"\"yes\" or \"no\""<<endl;
			cin>>round;
			if(round.compare("yes")==0 ||round.compare("no")==0)
			{
				break;
			}
			cout<<"sorry invalid entry"<<endl;
		}


	}while(round.compare("yes")==0);


	
  return 0;
}


