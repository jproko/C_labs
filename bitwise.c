/********************************************
*                                           *
* Author            : Julian Proko          *
* Purpose           : C Programming Lab     *
* Section           : 4.0                   *
* Version           : 2.0                   *
* Description       : Bitwise Operators     *
* Date Created      : 23/04/2021            *
* Last Modification : 23/04/2021            *
*                                           *
*********************************************/
#include <stdio.h>

int main()
{
    //Through this piece of code, we are going to dispay examples of bitwise operations
    //bit represantation of 90 = 1011010
    unsigned short int numA= 90;
    //bit represantation of 106 = 1101010
    unsigned short int numB= 106;

    //This line should print decimal number 74
    //Number 74 has bit represantation of 90 bitwise AND 106 = 1001010
    printf("The outcome of 90 bitwise AND 106, equals:%hu\n", numA&numB);

    //This line should print decimal number 122
    //Number 122 has bit represantation of 90 bitwise ΟR 106 = 1111010
    printf("The outcome of 90 bitwise OR 106, equals:%hu\n", numA|numB);

    //This line should print decimal number 48
    //Number 48 has bit represantation of 90 bitwise EXCLUSIVE OR 106 = 0110000
    printf("The outcome of 90 bitwise EXCLUSIVE OR 106, equals:%hu\n", numA^numB);

    //This line should print decimal number 65445
    //Given that the architecture we are running this programm gives 16 bits for short int
    //Additionally to the fact that the int type is unsigned
    //bit represantation of 1 suplement of 90 = 111111111 - 0100101
    printf("The outcome of 90s 1 supplement, equals:%hu\n", ~numA);

    //This line should display number 180
    //Left shift by 1 of 90 has a bit reprasantation of = 1011010 0
    //Left shift is also known as the multiplication by 2
    printf("The outcome of 90s left shift by 1, equals:%hu\n", numA<<1);

    //This line should display number 180
    //Left shift by 1 of 90 has a bit reprasantation of = 0 101101 x 0 
    //Left shift is also known as the integer division by 2
    printf("The outcome of 90s right shift by 1, equals:%hu\n", numA>>1);




    return 0;
}