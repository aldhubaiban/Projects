
#include "dealer.h"
#include "player.h"

#include <iostream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

void dealer_hit(struct Dealer list[])
{
	 int i;
	 int j;
	 int sum=0;
	 bool dealer_hit=false;

  for (i=1;i<12;i++)
	{
		  // to stop hitting the dealer condtion 
		  if(list[0].bust==true|| dealer_hit==true)
		  {
		  break;
		  }
  		// give a dealer card 
  		list[0].dealer_cards[i]=cards();
  		list[0].counter++;

		  // ace can be 1 or 11 
		  dealer_ace(list);

			for(j=0;j<list[0].counter;j++)
			{
				// sum dealers cards 
				sum+=list[0].dealer_cards[j];		
			}
			
			if(sum>21)
			{
			   list[0].bust=true;
					
			}
			else if(sum>=17)
			{
				dealer_hit=true;
			}
				 
		  // reset varaible
		
		  sum=0;
  }	
}

void give_dealer_card(struct Dealer dealer[])
{
  dealer[0].counter=0;
  dealer[0].dealer_cards[0]=cards();
  dealer[0].counter++;
  cout<<"\nDealer card is " <<dealer[0].dealer_cards[0]<< " and a hidden card\n"<<endl;
}

void dealer_ace(struct Dealer list[])
{

  int sum;
	int j;
	int k;
	int ACE=11;


	 for(j=0;j<list[0].counter;j++)
	 {
      sum=0;
		  if(list[0].dealer_cards[j]==1 || list[0].dealer_cards[j]==11)
			{
				  list[0].dealer_cards[j]=ACE;

				  for(k=0;k<list[0].counter;k++)
					{
						sum+=list[0].dealer_cards[k];	
					}

				  if(sum>21){list[0].dealer_cards[j]=1;}
				  else if(sum<=21){list[0].dealer_cards[j]=11;}
					sum=0;
			}

	 }

}

void dealer_sum(struct Dealer list_dealer[])
{
  int i;
	
	for (i=0;i<list_dealer[0].counter;i++)
	{
		list_dealer[0].sum_cards+=list_dealer[0].dealer_cards[i];
	}

}

void dealer_display(struct Dealer list[])
{
  int card=1;
  int i;
	cout<<"*************************************************"<<endl;
	cout<<"Dealer cards"<<endl;

	for (i=0;i<list[0].counter;i++)
	{
		if (list[0].dealer_cards[i]==1 ||list[0].dealer_cards[i]==11)
		{
			cout<<"card "<<card<<": ACE"<<endl;
			card++;
			continue;
		}
		cout<<"card "<<card<<": "<<list[0].dealer_cards[i]<<endl;
		card++;
	}
  
  dealer_sum(list);
  cout<<"Dealer total is: "<<list[0].sum_cards<<endl;

}

void determine_winner_split(struct player list[],struct Dealer list_dealer[],int i)
{
  int j;
  int player=i;
  bool determine_split=true;
  player++;
  for(j=0;j<2;j++)
  {

    if(determine_split==true)
    {
        //busted
        if(list[i].split1_bust==true )
        {

          cout<<"player "<<player<<endl;
          cout<<"split 1: total: "<<list[i].split_sum1<<endl;
          cout<<"split 1: Busted"<<endl;
          determine_split=false;
          continue;
        }

        //blackjack 
        else if (list[i].split1_blackjack_==true)
        {

          cout<<"player "<<player<<endl;
          cout<<"split 1: total: "<<list[i].split_sum1<<endl;
          cout<<"split 1: BlackJack"<<endl;
          list[i].player_balance+=(3*list[i].player_bet)/2 +list[i].player_bet;
          determine_split=false;
          continue;
        }
        // TIE
        else if(list[i].split_sum1==list_dealer[i].sum_cards)
        {
           cout<<"player "<<player<<endl;
           cout<<"split 1: total: "<<list[i].split_sum1<<endl;
           cout<<"split 1: Tie"<<endl;
          list[i].player_balance+= list[i].player_bet;
          if(list[i].DoubleDown==true)
          {
            list[i].player_balance+=list[i].player_bet;
          }
          determine_split=false;
          continue;
        }
            
         
        
        //win 
        else if(list_dealer[0].bust==true ||list_dealer[0].sum_cards<list[i].split_sum1)
        {
          cout<<"player "<<player<<endl;
          cout<<"split 1: total: "<<list[i].split_sum1<<endl;
          cout<<"split 1: Win"<<endl;

          list[i].player_balance+= 2*list[i].player_bet;
          if(list[i].DoubleDown==true)
          {
            list[i].player_balance+=2*list[i].player_bet;
          }
          determine_split=false;
          continue;
        }
        //lost
        else if(list_dealer[0].sum_cards>list[i].split_sum1)
        {
          cout<<"player "<<player<<endl;
          cout<<"split 1: total: "<<list[i].split_sum1<<endl;
          cout<<"split 1: Lost"<<endl;
          determine_split=false;
          continue;
        }
        determine_split=false;
        continue;
      }

        //busted
       if(list[i].split2_bust==true )
        {

          cout<<"player "<<player<<endl;
          cout<<"split 2: total: "<<list[i].split_sum2<<endl;
          cout<<"split 2: Busted"<<endl;
          
          continue;
        }

        //blackjack
        else if (list[i].split2_blackjack_==true)
        {

          cout<<"player "<<player<<endl;
          cout<<"split 2: total: "<<list[i].split_sum2<<endl;
          cout<<"split 2: BlackJack"<<endl;
          list[i].player_balance+=(3*list[i].player_bet)/2 +list[i].player_bet;
          list[i].split2_blackjack_=false;
          continue;
        }
        //tie
        else if(list[i].split_sum2==list_dealer[i].sum_cards)
        {
           cout<<"player "<<player<<endl;
           cout<<"split 2: total: "<<list[i].split_sum2<<endl;
           cout<<"split 2: Tie"<<endl;
          list[i].player_balance+= list[i].player_bet;
          if(list[i].DoubleDown==true)
          {
            list[i].player_balance+=list[i].player_bet;
          }
          list[i].split_sum1=0;
          continue;
        }
        //win
        else if(list_dealer[0].bust==true ||list_dealer[0].sum_cards<list[i].split_sum2)
        {
          cout<<"player "<<player<<endl;
          cout<<"split 2: total: "<<list[i].split_sum2<<endl;
          cout<<"split 2: Win"<<endl;

          list[i].player_balance+= 2*list[i].player_bet;
          if(list[i].DoubleDown==true)
          {
            list[i].player_balance+=2*list[i].player_bet;
          }
          list[i].split_sum1=0;
          continue;
        }
        //lost
        else if(list_dealer[0].sum_cards>list[i].split_sum2)
        {
          cout<<"player "<<player<<endl;
          cout<<"split 2: total: "<<list[i].split_sum2<<endl;
          cout<<"split 2: Lost"<<endl;
          list[i].split_sum1=0;
          continue;
        }





      }

   
}

void determine_winner(struct player list[], int num_of_players, struct Dealer list_dealer[])
{
  int i;
  
cout<<"\n\n*********************************************"<<endl;



for (i=0;i<num_of_players;i++)
{

  int player=i;
  player++;
cout<<"-------------------------------------"<<endl;
  if(list[i].splits2==true)
  {
  split_sum(list,i);
  
  determine_winner_split(list,list_dealer,i);
  cout<<"-------------------------------------"<<endl;
  continue;
  }
  player_sum(list,i);


cout<<"Hand total of player "<<player<<":  "<<list[i].hand_total<<endl;

  if(list[i].surrender==true )
  {
    cout<<"player "<<player<<": surrendered"<<endl;
    list[i].hand_total=0;
        continue;
  }
  else if(list[i].bust==true)
  {
    cout<<"player "<<player<<": Busted"<<endl;
    list[i].hand_total=0;
    continue; 
  }
  else if(list[i].blackjack_==true && list_dealer[0].sum_cards==21)
  {
  cout<<"player "<<player<<": Tie"<<endl;
  list[i].player_balance+= list[i].player_bet;
  continue; 
  }
  else if(list[i].blackjack_==true )

  {
    cout<<"player "<<player<<": BlackJack"<<endl;
    list[i].player_balance+=(3*list[i].player_bet)/2 +list[i].player_bet;
    list[i].hand_total=0;
    continue;
  }

  else if(list_dealer[0].bust==true || list_dealer[0].sum_cards<list[i].hand_total)
  {
    cout<<"player "<<player<<": Win"<<endl;
    list[i].player_balance+= 2*list[i].player_bet;
    if(list[i].DoubleDown==true)
    {
      list[i].player_balance+=2*list[i].player_bet;
    }
    list[i].hand_total=0;
    continue;
  }
  //dealer win 
  else if(list_dealer[0].sum_cards>list[i].hand_total)
  {
    cout<<"player "<<player<<": Lost"<<endl;
    list[i].hand_total=0;
    continue;
  }
  // push
  else if (list_dealer[0].sum_cards==list[i].hand_total)
  {
    cout<<"player "<<player<<": Tie"<<endl;
    list[i].player_balance+= list[i].player_bet;
    if(list[i].DoubleDown==true)
    {
      list[i].player_balance+=list[i].player_bet;
    }
    list[i].hand_total=0;
  }
  
  
  
  


}

cout<<"*********************************************"<<endl;

}

void reset_variables(struct player list[],struct Dealer list_dealer[], int num_of_players)
{

int i;
for(i=0;i<num_of_players;i++)
{
      list[i].num_of_cards=0;
      list[i].cards_counter=0;
      list[i].hand_total=0;
      list[i].split_condition=0;
      list[i].split_sum1=0;
      list[i].split_sum2=0;
      list[i].bust=false;
      list[i].surrender=false;
      list[i].blackjack_=false;
      list[i].DoubleDown=false;
      list[i].splits1=false;
      list[i].splits2=false;
      list[i].split1_bust=false;
      list[i].split2_bust=false;
      list[i].split1_blackjack_=false;
      list[i].split2_blackjack_=false;


}

list_dealer[0].counter=0;
list_dealer[0].sum_cards=0;
list_dealer[0].bust=false;
}

// project requirements

//Use vector 
void vector_stars()
{
vector<string> v;
int i;
for (i=0;i<20;++i)
{
  v.push_back("*");
  cout<<v[i];
}
cout<<endl;

}


//•Use operator overloading –5pts
//•Use const -5pts

ostream& operator<<(ostream& output,const Output& x)
{
  output<<"----- \nHow many players are playing\n-----  \n *NOTE:Max 5 players";

  return output;
}

