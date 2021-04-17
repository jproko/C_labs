/************************************************
*                                               *
* Author            : Julian Proko              *
* Purpose           : C Programming Challenge   *
* Version           : 2.0                       *
* Description       : Use of enum types         *
* Date Created      : 17/04/2021                *
* Last Modification : 17/04/2021                *
*                                               *
*************************************************/
#include <stdio.h>

int main()
{
    //we declare the needed enum type
    enum company {GOOGLE, FACEBBOK, XEROX, YAHOO, EBAY, MICROSOFT};

    //we declare and initialize the required company variables
    enum company company1 = XEROX;
    enum company company2 = GOOGLE;
    enum company company3 = EBAY;

    //we display the appropriate message to the user
    printf("Company: XEROX  \t Ranking: %d \n", company1);
    printf("Company: GOOGLE \t Ranking: %d \n", company2);
    printf("Company: EBAY   \t Ranking: %d \n", company3);

    return 0;
}