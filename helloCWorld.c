/********************************************
*                                           *
* Author            : Julian Proko          *
* Purpose           : C Programming Lab     *
* Version           : 1.0                   *
* Description       : Format Specifiers     *
* Date Created      : 09/04/2021            *
* Last Modification : 09/04/2021            *
*                                           *
********************************************/
#include <stdio.h>

int main()
{
    //Variable declarations/initializations
    //-------Characters-------
    char charValue = 'a';
    //-------Integer Related-------
    //signed
    signed short int siSoInt = -3;
    signed int siInt = - 7000;
    signed long int siLoInt = -1380567;
    signed long long int siLoLoInt = -1325e+12;
    //unsigned
    unsigned short int unSoInt = 3;
    unsigned int unInt = 7000;
    unsigned long int unLoInt = 1380567;
    unsigned long long int unLoLoInt = 13254e+12;
    //-------Floating point Related-------
    float fl = 3.14f;
    double doub = 3.141592653589793238462643383279502884197169399375105820974944;
    long double loDoub = 3.141592653589793238462643383279502884197169399375105820974944;
    //-------Floating point Related-------
    _Bool boolean = 0;

    //------------------------------------------------

    //Displaying the results on the screen, based uppon format specifiers
    printf("1. The character value equals: %c \n", charValue);
    printf("2. Display of the integer related variables: \n");
    printf("\tSigned integers: \n");
    printf("\t\tThe vector => short, normal, long, long long = %hd, %d, %ld, %lld \n", siSoInt, siInt, siLoInt, siLoLoInt);
    printf("\tUnsigned integers: \n");
    printf("\t\tThe vector => short, normal, long, long long = %hu, %u, %lu, %llu \n", unSoInt, unInt, unLoInt, unLoLoInt);
    printf("3. Display of the floating point related variables: \n");
    printf("\tThe vector => float, double, long double = %.2f, %lf, %Lf \n", fl, doub, loDoub);
    printf("4. The boolean value equals: %d \n", boolean);

    return 0;
}