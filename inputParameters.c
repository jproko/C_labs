/****************************************************
*                                                   *
* Author            : Julian Proko                  *
* Purpose           : C Programming Lab             *
* Version           : 2.0                           *
* Description       : Input (on start) parameters   *
* Date Created      : 16/04/2021                    *
* Last Modification : 16/04/2021                    *
*                                                   *
*****************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    //extracting the number of given char params
    //the argc parameter, holds the number of input arguments
    //nevertheless, the programm name itself is a given argument
    //therefore the user input arguments are stored from the second position or (index = 1) of the argv
    unsigned short int numberOfGivenArgs = argc-1;

    //for simplicity, we shall assume that we have only 2 given parameters
    //our parameters are seperated by space and are consisted as a sequence of chars
    char *programName = argv[0];
    char *argument1 = argv[1];
    char *argument2 = argv[2];

    //we display some output for clarification and demonstration purposes
    //first of all, let us display the number of user input given arguments 
    printf("Number of given input parameter equals to: %hu \n", numberOfGivenArgs);

    //now, let us display the output of those arguments using the %s (character sequence or string related) format specifier
    printf("The program name value equals: %s \n", programName);
    printf("The name of the user given input first parameter equals: %s \n", argument1);
    printf("The name of the user given input second parameter equals: %s \n", argument2);

    

    
    return 0;
}