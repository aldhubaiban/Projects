#include <stdio.h>

#define N 9

// global pointer to printing boared array
char *M;

//global variable to determine who begins the game (extra credit) 
int player_turn=0;

int checkForWinner(char *a)
{
    // pointer to access
    char *p=a;
    
    
    
    // player one horzintal winning
    if (*p=='X' && *(p+1)=='X' && *(p+2)=='X')
    {
        printf("\n**** Player 1 wins! ****\n");
        
        return 1;
    }
    
    else if (*(p+3)=='X' && *(p+4)=='X' && *(p+5)=='X')
    {
        printf("\n**** Player 1 wins! ****\n");
        
        return 1;
    }
    
    else if (*(p+6)=='X' && *(p+7)=='X' && *(p+8)=='X')
    {
        printf("\n**** Player 1 wins! ****\n");
        
        return 1;
    }
    
                // player two horzintal winning
                else if (*p=='O' && *(p+1)=='O' && *(p+2)=='O')
                {
                    printf("\n**** Player 2 wins! ****\n");
                    
                    return 2;
                }
                
                else if (*(p+3)=='O' && *(p+4)=='O' && *(p+5)=='O')
                {
                    printf("\n**** Player 2 wins! ****\n");
                    
                    
                    return 2;
                }
                
                else if (*(p+6)=='O' && *(p+7)=='O' && *(p+8)=='O')
                {
                    printf("\n**** Player 2 wins! ****\n");
                    
                    return 2;
                }
    
    // player one vertical winning
    else if (*p=='X' && *(p+3)=='X' && *(p+6)=='X')
    {
        printf("\n**** Player 1 wins! ****\n");
        
        return 1;
    }
    
    else if (*(p+1)=='X' && *(p+4)=='X' && *(p+7)=='X')
    {
        printf("\n**** Player 1 wins! ****\n");
        
        return 1;
    }
    
    else if (*(p+2)=='X' && *(p+5)=='X' && *(p+8)=='X')
    {
        printf("\n**** Player 1 wins! ****\n");
        
        return 1;
    }
    
                    // player two vertical winning
                    else if (*p=='O' && *(p+3)=='O' && *(p+6)=='O')
                    {
                        printf("\n**** Player 2 wins! ****\n");
                        return 2;
                    }
                    
                    else if (*(p+1)=='O' && *(p+4)=='O' && *(p+7)=='O')
                    {
                        printf("\n**** Player 2 wins! ****\n");
                        return 2;
                    }
                    
                    else if (*(p+2)=='O' && *(p+5)=='O' && *(p+8)=='O')
                    {
                        printf("\n**** Player 2 wins! ****\n");
                        
                        return 2;
                    }
    
    
    // player one diagonal winning
    else if (*p=='X' && *(p+4)=='X' && *(p+8)=='X')
    {
        printf("\n**** Player 1 wins! ****\n");
        
        return 1;
    }
    
    else if (*(p+2)=='X' && *(p+4)=='X' && *(p+6)=='X')
    {
        printf("\n**** Player 1 wins! ****\n");
        
        return 1;
    }
    
                        // player two diagonal winning
                        else if (*p=='O' && *(p+4)=='O' && *(p+8)=='O')
                        {
                            printf("\n**** Player 2 wins! ****\n");
                            
                            return 2;
                        }
                        else if (*(p+2)=='O' && *(p+4)=='O' && *(p+6)=='O')
                        {
                            printf("\n**** Player 2 wins! ****\n");
                            return 2;
                        }
    
    return 0;
    
    
    
    
}

void PrintBoard(char b[])
{
    //global pointer pointing to the array b
    M=b;
    printf(" %c|%c |%c\n",*M,*(M+1),*(M+2));
    printf("---+---+---\n");
    printf(" %c|%c |%c\n",*(M+3),*(M+4),*(M+5));
    printf("---+---+---\n");
    printf(" %c|%c |%c\n\n",*(M+6),*(M+7),*(M+8));
    
    
}

void PlayGame(int row1, int col1, char *a)
{
    
    // declare variables
    
    int i=0;
            char *p=a;
    
    
    int winner=0;
    
    
    for (i=0;i<N;i++)
    {
        
        // a player turn
        if (player_turn%2 ==0)
        {
            printf("Current move: player 1\n");
            
            
        }
        
        if (player_turn%2 ==1)
        {
            printf("Current move: player 2\n");
        }
        
        
        printf("Enter row: ");
        scanf("%d",&row1);
        
        // input validation
        while(row1>2 || row1<0)
        {
            printf("invalid entry please Enter row): ");
            scanf("%d",&row1);
        }
        
        printf("Enter column: ");
        scanf("%d",&col1);
        printf("\n");
        
        
        // input validation
        while(col1>2 || col1<0)
        {
            printf("invalid entry please Enter column: ");
            scanf("%d",&col1);
        }
        
        int index=(row1*3)+col1;
        
        
        
        
     
       
                      // spcae check if its empty or not
                       if(*(p+ index)!=' ')
                       {
                       printf("please choose another spot\n");
                       printf("Enter row: ");
                        scanf("%d",&row1);
                        
                        // input validation
                        while(row1>2 || row1<0)
                        {
                            printf("invalid entry please Enter row): ");
                            scanf("%d",&row1);
                        }
                       printf("Enter column: ");
                        scanf("%d",&col1);
                        printf("\n");
                        
                        // input validation
                        while(col1>2 || col1<0)
                        {
                            printf("invalid entry please Enter column: ");
                            scanf("%d",&col1);
                        }
                       }
       
      
       
       
       
        
        
        // conditions to place 'X'
        if (row1==0 &&col1==0 &&player_turn%2 ==0)
        {*p= 'X';}
        
        else if (row1==0 &&col1==1 &&player_turn%2 ==0)
        {*(p+1)= 'X';}
        else if (row1==0 &&col1==2 &&player_turn%2 ==0 )
        {*(p+2)= 'X';}
        else if (row1==1 &&col1==0  &&player_turn%2 ==0)
        {*(p+3)= 'X';}
        else if (row1==1 &&col1==1 &&player_turn%2 ==0)
        {*(p+4)= 'X';}
        else if (row1==1 &&col1==2 &&player_turn%2 ==0)
        {*(p+5)= 'X';}
        else if (row1==2 &&col1==0 &&player_turn%2 ==0)
        {*(p+6)= 'X';}
        else if (row1==2 &&col1==1 &&player_turn%2 ==0)
        {*(p+7)= 'X';}
        else if (row1==2 &&col1==2 &&player_turn%2 ==0)
        {*(p+8)= 'X';}
        
        
        
                                // conditions to place 'O'
                                if (row1==0 &&col1==0 &&player_turn%2 ==1)
                                {*p= 'O';}
                                
                                else if (row1==0 &&col1==1 &&player_turn%2 ==1)
                                {*(p+1)= 'O';}
                                else if (row1==0 &&col1==2 &&player_turn%2 ==1 )
                                {*(p+2)= 'O';}
                                else if (row1==1 &&col1==0  &&player_turn%2 ==1)
                                {*(p+3)= 'O';}
                                else if (row1==1 &&col1==1 &&player_turn%2 ==1)
                                {*(p+4)= 'O';}
                                else if (row1==1 &&col1==2 &&player_turn%2 ==1)
                                {*(p+5)= 'O';}
                                else if (row1==2 &&col1==0 &&player_turn%2 ==1)
                                {*(p+6)= 'O';}
                                else if (row1==2 &&col1==1 &&player_turn%2 ==1)
                                {*(p+7)= 'O';}
                                else if (row1==2 &&col1==2 &&player_turn%2 ==1)
                                {*(p+8)= 'O';}
          // increment
        player_turn++;
        
             // accessing the array
                PrintBoard(p);
        
                
        
                winner= checkForWinner(p);
        
        // condition to break after a player winning 
        if (winner==1)
        {
        player_turn=1;
            
            break ;
        }
        else if (winner==2)
        {
        player_turn=0;
            
            break ;
        }
        
        
        // condition when reach to a draw 
        if (i==8)
        {
            printf("\n**** The game has ended in a draw ****\n");
            break;
        }
      
    }
    
    
}






int main(void)
{
    char replay=0;
    
    do{
        printf("**** Tic-Tac-Toe ****\n");
        printf("   |   |  \n");
        printf("---+---+---\n");
        printf("   |   |  \n");
        printf("---+---+---\n");
        printf("   |   |  \n\n");
        
        
       
        
        char a[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
        
        PlayGame(0,0,a);
        
        
        // prompt the user to replay the game 
        printf("would you like to play another game? (y/n):\n\n");
        scanf(" %c",&replay);
        
        // input validation for 'y' as yes and 'n' as no
        while (replay !='y')
        {
            if (replay=='n')
            {
                break;
            }
            
            
            printf("would you like to play another game? (y/n):\n\n");
            scanf(" %c",&replay);
        }
        
        
    }while (replay !='n') ;
    
    return 0;
}








