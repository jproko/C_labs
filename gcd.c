/************************************************
*                                               *
* Author            : Julian Proko              *
* Purpose           : C Programming Challenge   *
* Section           : 7.0                       *
* Version           : 1.0                       *
* Description       : Implement gcd function    *
* Date Created      : 11/05/2021                *
* Last Modification : 11/05/2021                *
*                                               *
*************************************************/
#include <stdio.h>

//In this challenge, we are required to implement the mathematical function of gcd

//We start by declaring the function prototypes
unsigned short int gCd(unsigned int a, unsigned int b);
//input verifier
_Bool nonNegativityVerification(signed int a, signed int b);
void swapValuesInvokation(unsigned int a, unsigned int b);

//--------main function--------
int main()
{
    //variable initialization
    signed int givenParA = 0;
    signed int givenParB = 0;
    _Bool areParamsNonNegative=0;

    //ask the user to provide the desired numbers
    printf("Welcome to gcc calculator. Please, insert the two parameters.");
    scanf("%d, %d", &givenParA, &givenParB);
    printf("------------------------------------------------------------------------------------\n");
    printf("The given parameters received are: a: %d, b: %d\n", givenParA, givenParB);
    printf("------------------------------------------------------------------------------------\n");
    printf("Invoking input data verification phase:\n");
    printf("Non - negativity verification:\n");
    areParamsNonNegative = nonNegativityVerification(givenParA, givenParB)?1:0;
    switch (areParamsNonNegative)
    {
    case 1:
        printf("\tBoth given values, are postive.\n");
        printf("------------------------------------------------------------------------------------\n");
        swapValuesInvokation(givenParA,givenParB);
        break;
    
    default:
        printf("\tProgramm has shut down due to erroneous input data.\n");
        break;
    }

    return 0;
}

//--------non-negativity function--------
//We implement the non negativity verification function
//This function is going to check whether or not both input parameters are non negative
_Bool nonNegativityVerification(signed int a, signed int b)
{

    if(a<0 || b<0)
        return 0;
    return 1;
}

//--------swap values, gcd helper function--------
//We implement the swap values invokation
//For our gcd function to work correctly, we need a>=b
void swapValuesInvokation(unsigned int a, unsigned int b)
{
    printf("Swap values verification:\n");
    if(a>=b)
    {
        printf("\tNo swap needed:\n");
        printf("------------------------------------------------------------------------------------\n");
        printf("gcd: %hu\n", gCd(a, b));
    }
    else
    {
        printf("\tSwap performed.\n");
        printf("------------------------------------------------------------------------------------\n");
        printf("gcd: %hu\n", gCd(b, a));
    }
}

//--------gcd function--------
//We implement the gcd function
//The algorithm that we are going to use, is the Euclidean algorithm of gcd
//Function takes as input parameters two non negative integers and returns the gcd of them
//Without loss of generality, we assume that a>=b
//The function does not perform input verification. We are going to use another function for that
unsigned short int gCd(unsigned int a, unsigned int b)
{
    printf("Entered with parameters: %u, %u\n", a, b);
    unsigned int r=0;
    unsigned int q=0;
    while(b!=0)
    {
        q = a/b;
        r = a%b;
        printf("%u=%u*%u+r:%u\t(a,b,q,r)=(%u, %u, %u, %u)\n",a,b,q,r,a,b,q,r);
        a=b;
        b=r;
    }
    
    return a;
}
