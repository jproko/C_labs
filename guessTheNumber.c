/****************************************************
*                                                   *
* Author            : Julian Proko                  *
* Purpose           : C Programming Challenge       *
* Section           : 5.0                           *
* Version           : 2.0                           *
* Description       : Mini - game: guess the number *
* Date Created      : 06/05/2021                    *
* Last Modification : 06/05/2021                    *
*                                                   *
*****************************************************/
#include <stdio.h>
/*for this assignment, we include some extra feautures of context that
has not been provided to us yet*/
//-------------------------
#include <stdlib.h>
#include <time.h>
//-------------------------

int main()
{
    //Through this challenge, we are required to implement a game
    //This game will generate a random number from 0-20, and we have 5 tries to guess it
    //* small tip: If someone is more skeptical and carefull, he will notice that we can always win the game through binary search method *

    //random number generation code
    //-------------------------
    //variable initialization
    time_t t_var;
    //we initialize a random - number generator
    srand((unsigned)time(&t_var));
    //-------------------------

    //general variable initialization
    unsigned short int numberX = rand()%21;
    signed short int numberOfTries = 5;
    unsigned short int givenGuess = 0;
    _Bool numberWasFound = 0;
    

    //we generate the program interface with the user 
    //welcome display messages that will be displayed only at the beginning
    printf("Welcome to guess the number mini game\n");
    printf("You will have five guesses to find the generated number between 0 up to 20.\n");
    
    //we are entering the given answer verification loop
    //the code block will be executed at least one time, so we prefer to use do-while loop
    do
    {
        //we receive the numbe entered
        printf("\nPlease enter your guessed number:");
        scanf("%hu", &givenGuess);

        //we validate for correctness
        //we do not validate if input is not numerical
        //if given input is outside of margin, we issue a penalty of -2 guesses 
        if(givenGuess<0 || givenGuess>20)
        {
            printf("\nThe entered value was outside of [0-20].\n");
            printf("You received a penalty of -2 tries.\n");
            numberOfTries -=2;
            printf("NUmber of remaining tries: %hd\n", numberOfTries);    
        }
        else
        {
            //the input is acceptable, therefore we check input location
            if(givenGuess==numberX)
            {
                //display congratulation message and set found flag as true
                printf("\nCongratulations on finding the number! You won the game\n");
                numberWasFound = 1;
            }
            else if(givenGuess<numberX)
            {
                printf("\nYour guess is below the number. The real question is, how low?\n");
            }
            else
            {
                printf("\nYour guess is higher than the number. The real question is, how much higher?\n");
            }
            //in any case, one try has been issued
            numberOfTries -=1;
            printf("NUmber of remaining tries: %hd\n", numberOfTries);
        }
    }
    //we continue to loop untill either number has been found or number of tries has been expired
    //do -> code while(true);
    //so in order for use to continue, we both want number not to be found AND number of tries to be positive
    while (numberWasFound==0 && numberOfTries>0);

    if(numberWasFound)
    {
        printf("\nThank you for playing with us.");
        printf("Hope to see you soon.\n");
    }
    else
    {
        printf("\nThe best lessons come from our greatest losses. Keep working and the success will knock your door.\n");
        printf("The hidden number was: %hu.\n", numberX);
        printf("Thank you for playing with us.");
        printf("Hope to see you soon.\n");
    }
    
    return 0;
}