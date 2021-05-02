/************************************************
*                                               *
* Author            : Julian Proko              *
* Purpose           : C Programming Challenge   *
* Section           : 4.0                       *
* Version           : 1.0                       *
* Description       : Diagnostics: Print sizeof *
* Date Created      : 02/05/2021                *
* Last Modification : 02/05/2021                *
*                                               *
*************************************************/
#include <stdio.h>

int main()
{
    //We have to print the size of the next data types

    //1. signed int
    printf("The size of signed int is: %lu bytes\n", sizeof(signed int));

    //2. charachter
    printf("The size of character is: %lu bytes\n", sizeof(char));

    //3. signed long int
    printf("The size of signed long int is: %lu bytes\n", sizeof(signed long int));

    //4. signed long long int
    printf("The size of signed long long int is: %lu bytes\n", sizeof(signed long long int));

    //5. double
    printf("The size of double int is: %lu bytes\n", sizeof(double));

    //6. long double
    printf("The size of long double int is: %lu bytes\n", sizeof(long double));



    return 0;
}