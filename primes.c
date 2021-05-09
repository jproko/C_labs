/************************************************************
*                                                           *
* Author            : Julian Proko                          *
* Purpose           : C Programming Challenge               *
* Section           : 6.0                                   *
* Version           : 1.0                                   *
* Description       : Print all the primes beetween 0-100   *
* Date Created      : 08/05/2021                            *
* Last Modification : 08/05/2021                            *
*                                                           *
*************************************************************/
#include <stdio.h>

int main()
{
    //In this challenge, we are required to print all the prime numbers from 1-100
    //A prime number, is a number that can only be divided by itself and 1
    //By default, we hardcode the first two primes that are 2,3
    //We initialize the array to be 100 spaces (overkill) due to the fact that we are not certain how many primes are
    //(there are of course mathematical ways to check for #primes in any range, but it is out of this assginments scope)

    //We initialize the first two primes. All other 98 items will be equal to zero
    //Due to the fact 0 is not a prime number, we can be certain that the first 0 to be found would be a bound

    //One way to check any number whether or not is a prime number, is to check if it is divided or not by all the previous primes
    //Therefore, for every number from 1 - 100, we can check if it is divided by other primes.
    //If not, then we have a new prime number.
    //Aditionaly, we can skip all even numbers, due to the fact that by default, they are divided by 2 (k = 2n, for some n \in N*)
    
    //variable declaration and initialization
    unsigned short int primes[100] ={2,3};
    unsigned short int i =0;
    unsigned short int primeIndex = 0;
    _Bool primeFound = 1;

    //this loop. iterrates through range [4-100]
    for (i = 5;i<=100;i+=2)
    {
        //while we havent reached the end of prime table, repeat
        while(primes[primeIndex]!=0)
        {
            //if i is divisible by prime number, we havent found the desired prime number
            //so we break the iteration
            if(i%primes[primeIndex]==0)
            {
                primeFound = 0;
                break;
            }
            //if this line is invoked, then we havent reached the end of stored primes 
            //Adittionally, current i is still candidate for being prime, so we continue to check
            primeIndex+=1;
        }

        //if i is still prime and has not been rejected yet, we insert it in our table, in the last avalable spot
        //the index is being kept by primeIndex +=1
        if(primeFound==1)
        {
            primes[primeIndex]=i;
        }
        
        //in any case, we initialize the status of prime flag and index to 0
        primeFound=1;
        primeIndex = 0;
    }

    //we print the results
    printf("Printing list of all primes:");
    while(primes[primeIndex]!=0)
    {
        printf("%hu, ", primes[primeIndex]);
        primeIndex+=1;
    }
    printf("end of list\n");

    return 0;
}