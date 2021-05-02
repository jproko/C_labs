/************************************************************
*                                                           *
* Author            : Julian Proko                          *
* Purpose           : C Programming Challenge               *
* Section           : 4.0                                   *
* Version           : 1.0                                   *
* Description       : Minutes to Days and Years converter   *
* Date Created      : 20/04/2021                            *
* Last Modification : 20/04/2021                            *
*                                                           *
*************************************************************/
#include <stdio.h>

int main()
{
    //we first set the fraction denominators of minutes in a Day and Minutes in a Year
    //minutes in a day
    unsigned short int minutesPerDay = 24*60;
    unsigned long int minutesPerYear = minutesPerDay * 365;

    //after specifying the appropriate denominators, we then extract the necessary fractions
    
    //declaration and initialization of appropriate variables
    //we declare and initialize the needed variable for user input
    unsigned long int givenInput = 0;
    double givenMinutesToDays = 0.0;
    double givenMinutesToYears = 0.0;
    
    //first of all, we ask the user to insert input 
    //we do not make validation of input given that it is out of our needed scope for this challenge
    printf("Please enter the number of desired positive minutes: \n");
    scanf("%lu", &givenInput);

    //we now extract the fraction
    givenMinutesToDays = givenInput/(double)minutesPerDay;
    givenMinutesToYears = givenInput/(double)minutesPerYear;

    //we present the necessary output to the user
    printf("-------------------------------------------------\n");
    printf("One day has %hu minutes per day. (denominator a) \n", minutesPerDay);
    printf("One day has %lu minutes per year. (denominator b) \n", minutesPerYear);
    printf("-------------------------------------------------\n");
    printf("The given input of minutes was recorded as: %lu \n", givenInput);
    printf("-------------------------------------------------\n");
    printf("The given input is %lf days \n", givenMinutesToDays);
    printf("The given input is %lf years \n", givenMinutesToYears);
    
    return 0;
}