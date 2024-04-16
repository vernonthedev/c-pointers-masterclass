//Simple Betting Game
// "Jack, Queen, King" - computer shuffles these cards
//player has to guess the position of the queen
//if he wins, he takes 3*bet
//if he looses, he looses the bet amount.
//player has $100 initially.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//global cash var
int cash = 100;

// the play function
void Play(int bet)
{
    char C[3] = {'J', 'Q', 'K'}; //define our array of cards
    printf("Shuffling.....\n");
    srand(time(NULL)); //generate random numbers based on time or seeding the random numbers based on time
    int i;
    //shuffle the cards five times
    for(i = 0; i < 5; i++)
    {
        //make sure we pick two positions for the chars
        int x = rand() % 3;
        int y = rand() % 3;
        //swap the characters during the shuffle at position x and y
        int temp = C[x]; 
        C[x] = C[y]; 
        C[y] = temp;

    }
    int playersGuess;
    printf("What's the position of the Queen -> 1, 2 or 3? ");
    scanf("%d", &playersGuess);
    if(C[playersGuess - 1] == 'Q')
    {
        cash += 3*bet;
        printf("You Win! Result = %c %c %c Total Cash = %d", C[0],C[1],C[2],cash);
        return ;
    }else
    {
        cash -= bet;
        printf("You Loose! Result = %c %c %c Total Cash = %d", C[0],C[1],C[2],cash);
    }

}


// the main execution function
int main()
{
    int bet;
    printf("***Welcome to the Virtual Casino***\n");
    printf("Total Cash = $%d\n",cash);
    while(cash > 0)
    {
        printf("What's your bet? $");
        scanf("%d, ",&bet);
        // if run out of cash, then we exit the game
        if(bet == 0 || bet > cash) break;
        Play(bet);
        printf("\n****************************************\n");

    }
}