
#include "dealer.h"
#include "player.h"
#include <iostream>
#include <time.h>
#include <string>
using namespace std;


void intial_balnce(struct player list[], int num_of_players)
{
	int i;
	for (i=0;i<num_of_players;i++)
	{
    	list[i].player_balance=1000;
    	
  	}   
}


void bet(struct player list[], int num_of_players)
{
  int i=0;
  int player_number=1;
	for (i=0;i<num_of_players;i++)
	{
		cout<<endl;
		cout<<"player "<<player_number<<" balance : $"<<list[i].player_balance<<endl;
		cout<<"------------"<<endl;
		cout<<"what is your bet?"<<endl;
		cout<<"------------"<<endl;
		cout<<"minimum bet is $5 and maximum bet is $100: \n";
		cin>>list[i].player_bet;

		//condition for player bet to be between 5 and 100 
		while(list[i].player_bet<5 ||list[i].player_bet>100)
			{
			cout<<"invalid bet"<<endl;
			cout<<"please enter a bet between 5 to 100"<<endl;
			cin>>list[i].player_bet;
			}

		// decrease the amount from player balance 
		list[i].player_balance-=list[i].player_bet;

		// increment for a local variable  
		player_number++;
	}
}

void give_Two_Cards(struct player list[], int num_of_players)
{
	int i,j;
	for(i=0;i<num_of_players;i++)
  	{
		for (j=0;j<2;j++)
    	{ 
        	// fill players card
    		list[i].player_cards[j]=cards();

    		list[i].num_of_cards++;
    		list[i].cards_counter++;
   		}
	}
}

void check_bust(struct player list[], int i)
{
   int j;
   int sum=0;
   
   // a loop to get the sum of all cards in hand 
    for (j=0;j<list[i].cards_counter;j++)   {sum+=list[i].player_cards[j];}
	// check if sum is over 21 
    if(sum>21)  {list[i].bust=true;}
    
}

void hit(struct player list[],int i)
{
	int j;
	string input;
		do{

			list[i].num_of_cards++;
			// give him another card loop
  			for( j=list[i].cards_counter;j<list[i].num_of_cards;j++)
  			{
    	
    			list[i].player_cards[j]=cards();
  			}

  	
		
		  	// to avoid writing a big variablle name as condition  
		  	list[i].cards_counter=j;

		  	// for ACE could be 1 or 11
		 	 Ace(list,i);
		 	 // to check if thetotal cards is over 21
			 check_bust(list,i);

		 	 display_cards(list,i);
		
			if(list[i].bust==true) {break;}
			// condition to insure input is only "hit" or "stand"
			while(1)
			{
				cout<<"would like to \"hit\" or \"stand\""<<endl;
				cin>> input;
				if(input.compare("hit")==0 ||input.compare("stand")==0)
				{
					break;
				}
				cout<<"invalid entry:"<<endl;
				
			}

		}while(input.compare("hit")==0);
}

void double_down(struct player list[], int i)
{
	
	list[i].DoubleDown=true;
	// decrease same amount of bet from player balance 
	list[i].player_balance-=list[i].player_bet;	
	
	// number of cards player have b
 	list[i].num_of_cards++;

    list[i].player_cards[2]=cards();  
  	

	
	// to count the cards
	list[i].cards_counter++;
	
}

void stand(struct player list[],int i)
{
	Ace(list,i);
	int j;
	int sum=0;
	 
	 // black jack check
	for(j=0;j<list[i].cards_counter;j++)
		{
			sum+=list[i].player_cards[j];
		}
	
	if(sum==21)
		{
			list[i].blackjack_=true;
		}
}

void surrender(struct player list[], int i)
{
	list[i].player_balance+=list[i].player_bet/2;
	list[i].surrender=true;
}

void Ace(struct player list[], int i)
{

	int j;
	int k;
	int ACE=11;
	int sum=0;


	for (j=0;j<list[i].cards_counter;j++)
	{


		

		if (list[i].player_cards[j]==1 ||list[i].player_cards[j]==11)
		{
			list[i].player_cards[j]=ACE;

			for (k=0;k<list[i].cards_counter;k++)
			{
				sum+=list[i].player_cards[k];					
			}
			if(sum>21) { list[i].player_cards[j]=1;  }

			else { list[i].player_cards[j]=11; }

		}
	}
}

void gameoptions(struct player list[],int num_of_players)
{
	int i;
	string option;	

	for(i=0;i<num_of_players;i++)
	{
		cout<<endl;
		display_cards(list,i);
		if(list[i].player_cards[0] ==list[i].player_cards[1]|| (list[i].player_cards[0]==11 &&list[i].player_cards[1]==1) || (list[i].player_cards[0]==1 &&list[i].player_cards[1]==11))
		{
			cout<<"Game Options\n--------------------------------------------"<<endl;
			cout<<"hit is \"hit\""<<endl;
			cout<<"stand is \"stand\""<<endl;
			cout<<"double down is \"d\""<<endl;
			cout<<"surrender is \"surrender\""<<endl;
			cout<<"split is \"split\""<<endl;
			cin>> option;
		}
		else 
		{
			cout<<"Game Options\n--------------------------------------------"<<endl;
			cout<<"hit is \"hit\""<<endl;
			cout<<"stand is \"stand\""<<endl;
			cout<<"double down is \"d\""<<endl;
			cout<<"surrender is \"surrender\""<<endl;
			cin>> option;
		}

			// to insure 
		while(1)
		{


			if(option.compare("hit")==0)
			{
				hit(list,i);
				break;
			}
			else if(option.compare("stand")==0)
			{
				stand(list,i);
				break;
			}
			else if(option.compare("d")==0)
			{
				double_down(list,i );
				Ace(list,i);
				check_bust(list,i);
				display_cards(list,i);
				break;
			}
			else if(option.compare("surrender")==0)
			{
				surrender(list,i);
				break;
			}
			else if(option.compare("split")==0)
			{
					split(list,i);
					break;
			}

				cout<< "\n\ninvalid input\n\n"<<endl;

			if(list[i].player_cards[0] ==list[i].player_cards[1]|| (list[i].player_cards[0]==11 &&list[i].player_cards[1]==1) || (list[i].player_cards[0]==1 &&list[i].player_cards[1]==11)  )
			{	
				cout<<"Game Options\n--------------------------------------------"<<endl;
				cout<<"hit is \"hit\""<<endl;
				cout<<"stand is \"stand\""<<endl;
				cout<<"double down is \"d\""<<endl;
				cout<<"surrender is \"surrender\""<<endl;
				cout<<"split is \"split\""<<endl;
				cin>> option;
			}
			else 
			{	cout<<"Game Options\n--------------------------------------------"<<endl;
				cout<<"hit is \"hit\""<<endl;
				cout<<"stand is \"stand\""<<endl;
				cout<<"double down is \"d\""<<endl;
				cout<<"surrender is \"surrender\""<<endl;
				cin>> option;
			}

		}// end of while 

	}
}

void display_cards(struct player list[], int i)
{
  	int j;
  	int player=i;
 	int card=1;
 	player++;
  	cout<<"Player "<<player<<endl;

	  for(j=0;j<list[i].cards_counter;j++)
	  {
	    
	    if(list[i].player_cards[j]==1 ||list[i].player_cards[j]==11)
	    {
	      cout<<"Card "<<card<<": ACE"<<endl;
	      card++;
	      continue;
	    }
	    cout<<"Card "<<card<<": "<<list[i].player_cards[j]<<endl;
	    card++;
	  }
	cout<<"--------------------------------------------"<<endl;
}

void player_sum(struct player list[],int i)
{
	int j;
		for(j=0;j<list[i].cards_counter;j++)
		{
			list[i].hand_total+=list[i].player_cards[j];
		}
}

int cards()
{
	
	int card= rand()%11 +1 ;
	return card;
}


void split(struct player list[],int i)
{

  	int j;
  	list[i].player_balance-=list[i].player_bet;


 	list[i].split1[0]=list[i].player_cards[0];
 	list[i].split2[0]=list[i].player_cards[1];


	list[i].split1[1]=cards();

	list[i].splits1=true;

	for(j=0;j<2;j++)
	{
	  list[i].player_cards[j]=list[i].split1[j];
	}

	list[i].split_condition=2;

	display_cards_split(list,i);
	switch_split(list,i);

	list[i].splits1=false;

	list[i].num_of_cards=2;
	list[i].cards_counter=2;
	list[i].splits2=true;

	list[i].split2[1]=cards();

	for(j=0;j<2;j++)
	{
	  list[i].player_cards[j]=list[i].split2[j];
	}
	display_cards_split(list,i);
	switch_split(list,i);



}

void switch_split(struct player list[], int i)
{
	string option;
	while(1)
	{

 		cout<<"Game Options \n  hit is \"hit\" \n  stand is \"stand\"  \n  double down is \"d\""<<endl;
		cin>>option;

		if(option.compare("hit")==0)
		{
		 	hit_split(list,i);
		 	break;
		}
		else if(option.compare("stand")==0)
		{
		 	stand_split(list,i);
		 	break;
		}
		else if(option.compare("d")==0)
		{
		 	double_down_split(list,i);
		 	display_cards_split(list,i);
		 	break;
		}

		cout<<"Invalid input"<<endl;
	}
}

void hit_split(struct player list[],int i)
{
  	int j;
  	int k;
  	string input;


  	do
  	{

    	list[i].num_of_cards++;
    	// give him another card loop
      	for( j=list[i].cards_counter;j<list[i].num_of_cards;j++)
      	{
     	 	list[i].player_cards[j]=cards();
     	}

    
    
      	// to avoid writing a big variablle name as condition  
      	list[i].cards_counter=j;

      	// for ACE could be 1 or 11
      	Ace(list,i);

      	if(list[i].splits1==true)
      	{
	        for(k=0;k<j;k++)
	        {
	          list[i].split1[k]=list[i].player_cards[k];
	        }

	    	list[i].split_condition=j;
      	}

       if(list[i].splits2==true)
      	{
	        for(k=0;k<j;k++)
	        {
	          list[i].split2[k]=list[i].player_cards[k];
	        }
      	}

      // to check if thetotal cards is over 21
   		check_bust_split(list,i);
      	display_cards_split(list,i);
    
  
      	if(list[i].split2_bust==true)
    	{
      		break;
    	}

      	if(list[i].split1_bust==true && list[i].splits1==true)
    	{
     		break;
   		}

      // condition to insure input is only "hit" or "stand"
     	while(1)
      	{
        	cout<<"would like to \"hit\" or \"stand\""<<endl;
        	cin>> input;
        	if(input.compare("hit")==0 ||input.compare("stand")==0)
        	{
         	 break;
        	}
        	cout<<"invalid entry:"<<endl;
        
    	 }

  	}while(input.compare("hit")==0);

}


void check_bust_split(struct player list[], int i)
{
   int j;
   int sum=0;
   
   if(list[i].splits1==true)
   {
    for (j=0;j<list[i].split_condition;j++)   

  // a loop to get the sum of all cards in hand 
    {sum+=list[i].split1[j];}
  

     
      if(sum>21)
      {
       list[i].split1_bust=true;
      }
    }

    if(list[i].splits2==true)
   {
    for (j=0;j<list[i].cards_counter;j++)   

  // a loop to get the sum of all cards in hand 
    {sum+=list[i].split2[j];}
  

     
      if(sum>21)
      {
       list[i].split2_bust=true;
      }
    }
    


}



void display_cards_split(struct player list[], int i)
{
	int j;
	int player=i;
  	int card=1;
 	player++;
  	cout<<"Player "<<player<<endl;


	if(list[i].splits1==true)
	{
  		cout<<"split 1"<<endl;
  		for(j=0;j<list[i].split_condition;j++)
  		{
    
    		if(list[i].split1[j]==1 ||list[i].split1[j]==11)
    		{
	     	 	cout<<"Card "<<card<<": ACE"<<endl;
	      		card++;
	      		continue;
    		}

   			cout<<"Card "<<card<<": "<<list[i].split1[j]<<endl;
    		card++;
  		}



		cout<<"--------------------------------------------"<<endl;
	}

	if(list[i].splits2==true)
	{
    	cout<<"split 2"<<endl;
  		for(j=0;j<list[i].cards_counter;j++)
  		{
    
   		 	if(list[i].split2[j]==1 ||list[i].split2[j]==11)
   			{
		      	cout<<"Card "<<card<<": ACE"<<endl;
		     	 card++;
		      	continue;
		    }

    		cout<<"Card "<<card<<": "<<list[i].split2[j]<<endl;
    		card++;
  		}



		cout<<"--------------------------------------------"<<endl;
	}
}


void split_sum(struct player list[],int i)
{
	int j;
	for(j=0;j<list[i].split_condition;j++)
	{
		list[i].split_sum1+=list[i].split1[j];
	}

	for(j=0;j<list[i].cards_counter;j++)
	{
		list[i].split_sum2+=list[i].split2[j];
	}


}

void stand_split(struct player list[],int i)
{
	Ace(list,i);
	int j;
	int sum=0;

	if(list[i].splits1==true)
	{
	  	for(j=0;j<list[i].split_condition;j++)
	  	{
	    	sum+=list[i].split1[j];
	  	}

		if(sum==21)
		{
	  		list[i].split1_blackjack_=true;
		}
	}

	if(list[i].splits2==true)
	{
	  	for(j=0;j<list[i].cards_counter;j++)
	  	{
	   		sum+=list[i].split2[j];
	  	}

		if(sum==21)
		{
		  list[i].split2_blackjack_=true;
		}
	}

}

void double_down_split(struct player list[], int i)
{
	int j;
  	if (list[i].splits1==true)
  	{
    	list[i].DoubleDown=true;
    	list[i].player_balance-=list[i].player_bet;

    	list[i].split_condition++;
    	list[i].player_cards[2]=cards();
    	Ace(list,i);
    	check_bust_split(list,i);

    	for(j=0;j<list[i].split_condition;j++)
    	{
     		list[i].split1[j]=list[i].player_cards[j];
    	}
  	}
    
    if (list[i].splits2==true)
  	{
    	list[i].DoubleDown=true;
    	list[i].player_balance-=list[i].player_bet;

    	list[i].cards_counter++;
   		list[i].player_cards[2]=cards();
    	Ace(list,i);
    	check_bust_split(list,i);
	    for(j=0;j<list[i].split_condition;j++)
	    {
	    	list[i].split2[j]=list[i].player_cards[j];
	    }
  	}

}

