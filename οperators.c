/********************************************
*                                           *
* Author            : Julian Proko          *
* Purpose           : C Programming Lab     *
* Section           : 4.0                   *
* Version           : 1.0                   *
* Description       : Example of Operators  *
* Date Created      : 20/04/2021            *
* Last Modification : 20/04/2021            *
*                                           *
*********************************************/
#include <stdio.h>

int main()
{
    //1. Arithmetic operators
    //through this piece of code, we indicate the use of prefix and postfix 
    //numerical operators in C (as well as many other languages)
    
    //we declare and initialize the appropriate variable
    unsigned int counter = 0;

    //the next line will display 0, even though we increment it
    printf("Counter value equals to: %d \n", counter++);
    
    //the next line will display 1, from the previous incremention
    printf("Counter value equals to: %d \n", counter);

    //the next line will display 2, due to the inline prefix incremention
    printf("Counter value equals to: %d \n\n", ++counter);
    
    //----------------------------------------------------------------------
    //2. Assignment operators

    printf("Printing the truth table of AND operator && \n");
    //The next line should print the vector (0, 0, 0, 1)
    printf("(%d, %d, %d, %d) \n", 0&&0, 0&&1, 1&&0, 1&&1);

    printf("Printing the truth table of OR operator || \n");
    //The next line should print the vector (0, 1, 1, 1)
    printf("(%d, %d, %d, %d) \n", 0||0, 0||1, 1||0, 1||1);

    printf("Printing the truth table of NOT operator ! \n");
    //The next line should print the vector (1, 0)
    printf("(%d, %d) \n\n", !0, !1);

    //----------------------------------------------------------------------
    //3. Assignment operators

    counter +=1;
    //the next line will display 3
    printf("Counter value equals to: %d \n", counter);

    counter -=8;
    //the next line will display -5
    printf("Counter value equals to: %d \n", counter);

    counter *=-1;
    //the next line will display 5
    printf("Counter value equals to: %d \n", counter);

    counter %=2;
    //the next line will display 1
    printf("Counter value equals to: %d \n", counter);

    counter /=2;
    //the next line will display 0
    printf("Counter value equals to: %d \n\n", counter);

    //----------------------------------------------------------------------
    //4. Relation operators

    //The next line should print 0 as answer
    printf("Is 4 = 2? : %d \n", 4==2);

    //The next line should print 1 as answer
    printf("Is 4 = 4? : %d \n", 4==4);

    //The next line should print 1 as answer
    printf("Is 4 not equal to 2? : %d \n", 4!=2);

    //The next line should print 0 as answer
    printf("Is 4 not equal to 4? : %d \n", 4!=4);

    //The next line should print 0 as answer
    printf("Is 4 > to 5? : %d \n", 4>5);

    //The next line should print 1 as answer
    printf("Is 4 > 2? : %d \n", 4>2);

    //The next line should print 1 as answer
    printf("Is 4 < to 5? : %d \n", 4<5);

    //The next line should print 0 as answer
    printf("Is 4 < 2? : %d \n", 4<2);

    //The next line should print 0 as answer
    printf("Is 4 >= 5? : %d \n", 4>=5);

    //The next line should print 1 as answer
    printf("Is 4 >= 4? : %d \n", 4>=4);

    //The next line should print 1 as answer
    printf("Is 5 >= 4? : %d \n", 5>=4);

    //The next line should print 1 as answer
    printf("Is 4 <= 5? : %d \n", 4<=5);

    //The next line should print 1 as answer
    printf("Is 4 <= 4? : %d \n", 4<=4);

    //The next line should print 0 as answer
    printf("Is 5 <= 4? : %d \n", 5<=4);




    
    return 0;
}