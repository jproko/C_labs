/************************************************
*                                               *
* Author            : Julian Proko              *
* Purpose           : C Programming Challenge   *
* Section           : 5.0                       *
* Version           : 1.0                       *
* Description       : Weekly salary calculator  *
* Date Created      : 06/05/2021                *
* Last Modification : 06/05/2021                *
*                                               *
*************************************************/
#include <stdio.h>

int main()
{
    //In this challenge, we are requested to implement a weekly salary calculator
    
    //First of all, we have to take as input a number, that represent the hours worked this week
    //Without loss of generality, we will assume that this number should be in [0,50] range
    
    //Variable declaration and initialization section
    unsigned short int weeklyHours=0;
    unsigned short int overtimeHours=0;
    float paymentPerHour = 12.00f;
    float totalPayment = 0.0f;
    float taxWithdrawall = 0.0f;
    _Bool areWeeklyHoursCorrect=0;

    //repetitive loop that ensures the given hours value is correct
    //we do not check for wrong input...we only check for wrong hour number input
    printf("Please enter the number of weekly hours you have worked:");
    do
    {
        scanf("%hu", &weeklyHours);
        areWeeklyHoursCorrect= (weeklyHours<0 || weeklyHours>50) ? 0:1;
        if(areWeeklyHoursCorrect==0)
            printf("Please enter a valid hours number:");
    }while(areWeeklyHoursCorrect==0);

    printf("The given hours are:%hu \n",weeklyHours);

    //calculate total payment 
    //the user takes as income 12.00$/hour for up to 40hours and 1.5 *12.00 = 18.00$/hour for overtime  
    if (weeklyHours<=40)
    {
        totalPayment = weeklyHours*paymentPerHour;
    }
    else
    {
        overtimeHours = weeklyHours-40;
        totalPayment = 40*paymentPerHour + overtimeHours*(1.5)*paymentPerHour; 
    }

    //calculate tax withdrawall
    //the tax for up to 300.00$ is 15%
    //the tax for the next 150.00$ is 20%
    //the tax for every next dollar is 25%
    if(totalPayment<=300)
    {
        taxWithdrawall = 0.15*totalPayment;
    }
    else if(totalPayment<=450)
    {
        taxWithdrawall = 0.15*300 + 0.2*(totalPayment-300);
    }
    else
    {
        taxWithdrawall = 0.15*300 + 0.2*150 +0.25*(totalPayment-450);
    }

    //we print the outpout to the user
    printf("---------------------------------------\n");
    printf("The total payment is: %.2f$\n", totalPayment);
    printf("The tax withdrawall is: %.2f$\n", taxWithdrawall);
    printf("The tax-free weekly income is: %.2f$\n", totalPayment - taxWithdrawall);

    return 0;
}