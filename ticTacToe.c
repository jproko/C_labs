/************************************************
*                                               *
* Author            : Julian Proko              *
* Purpose           : C Programming Challenge   *
* Section           : 7.0                       *
* Version           : 2.0                       *
* Description       : Mini-game: Tic-Tac-Toe    *
* Date Created      : 11/05/2021                *
* Last Modification : 11/05/2021                *
*                                               *
*************************************************/
#include <stdio.h>

//In this challenge, we are required to implement the simple game of tic tac toe
//We are going to use a 3x3 gr
//It is going to be player vs player game mode

//we include the stdlib.h header to clear screen after each players turn
#include <stdlib.h>

//declaring the grid that all functions will be able to access
char grid[3][3]=
{
    {' ', ' ', ' '}, //first row
    {' ', ' ', ' '}, //second row
    {' ', ' ', ' '}  //third row
};

char gridIndicator[3][3]=
{
    {'1', '2', '3'}, //first row
    {'4', '5', '6'}, //second row
    {'7', '8', '9'}  //third row
};

//function declaration
_Bool gameFunc(unsigned short int extractedRow, unsigned short int extractedCol, unsigned short int playersTurn);
void printGrid(void);
_Bool inputVerification(unsigned short int playerInput);
_Bool gridVerification(unsigned short int row, unsigned short col);
void placeOption(unsigned short int row, unsigned short col, unsigned short playersTurn);
_Bool isWin(unsigned short int playersTurn);
_Bool isWinRows(char givenTurn);
_Bool isWinCols(char givenTurn);
_Bool isWinPrimeDiags(char givenTurn);
_Bool isWinSecDiags(char givenTurn);
_Bool isDraw(void);


//------------------------------------------------------------------------------------------------------
//--------main function--------
int main()
{
    unsigned short int playerInput = 0;
    unsigned short int extractedRow = 0;
    unsigned short int extractedCol = 0;
    unsigned short int playersTurn = 0;
    _Bool isGameFinished = 0;

    while (isGameFinished==0)    
    {
        //print the current state of the grid
        printGrid();
        
        //take players input
        printf(">Player %hu turn: ", playersTurn+1);
        scanf("%hu",&playerInput);

        //if input is in desired range
        if(inputVerification(playerInput))
        {
            //we subtract 1 to aquire the necessary index
            //index mapping is as following
            //given number  : 1  2  3  4  5  6  7  8  9
            //row index     : 0  0  0  1  1  1  2  2  2     given number-1 / 3
            //column index  : 0  1  2  0  1  2  0  1  2     given number-1 % 3
            playerInput -=1;
            extractedRow = playerInput/3;
            extractedCol = playerInput%3;            
            
            //grif verification function, checks whether or not the given position is empty
            if(gridVerification(extractedRow, extractedCol))
            {
                //The space is empty
                //After receiving row and column, it places X or O accordingly to players turn
                placeOption(extractedRow, extractedCol, playersTurn);
                //In this case we invoke game functionality which checks for win or draw
                //If game ends by win or draw, we terminated
                if(isGameFinished=gameFunc(extractedRow, extractedCol, playersTurn))
                    break;
            }
            else
            {
                //The space is occupied
                printf("Error: Chosen space is occupied\n");
                break;  
            }
            
        }
        else
        {
            //Players input is out of range
            printf("Error: Player input was out of bounds.\n");
            break;
        }

        //if players turn =0 => players turn will be 0+1 = 1%2 = 1
        //if players turn =1 => players turn will be 1+1 = 2%2 =0
        playersTurn+=1;
        playersTurn%=2;
    }

    return 0;
}

//------------------------------------------------------------------------------------------------------
//This function is responsible for printing a normalized and beautiful UI for the grid
void printGrid(void)
{
    //clear screen from anything
    system("clear");

    //UI Introduction
    printf("\t    Tic Tac Toe\n");
    printf("\nPlayer 1: X-s");
    printf("\t    Player 2: O-s\n\n");
    
    //UI grid print
    unsigned short int rows = 0;
    unsigned short int cols = 0;
    printf("\t _________________");
    printf("\t\t\t");
    printf("\t _________________\n");
    for (rows;rows<3;rows+=1)
    {
        printf("\t|     |     |     |");
        printf("\t\t\t");
        printf("\t|     |     |     |");
        printf("\n\t|");
        for (cols;cols<3;cols+=1)
        {
            printf("  %c  |",grid[rows][cols]);
        }
        printf("\t\t\t\t|");
        cols = 0;
        for (cols;cols<3;cols+=1)
        {
            printf("  %c  |",gridIndicator[rows][cols]);
        }
        printf("\n\t|_____|_____|_____|");
        printf("\t\t\t");
        printf("\t|_____|_____|_____|\n");
        
        cols = 0;
    }

    printf("\n\n");
}

//------------------------------------------------------------------------------------------------------
//This function is responsible for checking whether or not the given input is a place inside the grid
_Bool inputVerification(unsigned short int playerInput)
{
    if(playerInput>=1 && playerInput<=9)
        return 1;
    return 0;
}

//------------------------------------------------------------------------------------------------------
//This function is responsible for checking whether or not the grid space is empty or not
_Bool gridVerification(unsigned short int row, unsigned short col)
{
    if(grid[row][col]=='X' || grid[row][col]=='O')
        return 0;
    return 1;   
}

//------------------------------------------------------------------------------------------------------
//This function is responsible for checking whether or not the grid space is empty or not
void placeOption(unsigned short int row, unsigned short col, unsigned short playersTurn)
{
    if (playersTurn ==0)
    {
        grid[row][col] = 'X';
    }
    else if(playersTurn==1)
    {
        grid[row][col] = 'O';
    }  

    return;
}

//This function is responsible for implementing the basic game functionality
//This function returns true only when the game is finished and false otherwise
//------------------------------------------------------------------------------------------------------
_Bool gameFunc(unsigned short int extractedRow, unsigned short int extractedCol, unsigned short int playersTurn)
{
    //first, check whether or not the player won 
    if(isWin(playersTurn))
    {
        printGrid();
        printf("Win: Player %hu wins\n", playersTurn+1);
        return 1;
    }

    //if the player did not win, check whether or not the player's move gave a draw
    if(isDraw())
    {
        printGrid();
        printf("Its a draw\n");
        return 1;
    }
    return 0;
}

//This function is responsible for checking on whether or not game is a draw
//------------------------------------------------------------------------------------------------------
_Bool isDraw(void)
{
    unsigned short int i=0;
    unsigned short int j=0;
    unsigned short int occupiedPositions = 0;

    for (i;i<3;i+=1)
    {
        for (j;j<3;j+=1)
        {
            //if grid[i][j] == X or grid[i][j] == O, occupiedPositions+=1 
            occupiedPositions += (grid[i][j]=='X' || grid[i][j]=='O') ?1:0;
        }
    }   

    //if all positions are occupied, return draw
    if (occupiedPositions==9)
        return 1;
    return 0;
}

//------------------------------------------------------------------------------------------------------
//This function is responsible for checking if the current player that just played won
_Bool isWin(unsigned short int playersTurn)
{
    //declare and initialize checking charachter
    char checkingCharachter = 'E';

    //if players turn is 0
    switch (playersTurn)
    {
    case 0:
        checkingCharachter = 'X';
        break;
    
    //if players turn is 1
    case 1:
        checkingCharachter = 'O';
        break;

    default:
        printf("Internal Error: Function isWin can not operate.\n");
        break;
    }

    //if the player that we are checking, has won in any horizontal, vertical or diagonal row, return win
    if(isWinRows(checkingCharachter) || isWinCols(checkingCharachter) || isWinPrimeDiags(checkingCharachter) || isWinSecDiags(checkingCharachter))
        return 1;
    return 0;
}

//This function checks whether or not the player has won in the rows
//------------------------------------------------------------------------------------------------------
_Bool isWinRows(char checkingCharachter)
{
    //checking the rows for win
    unsigned short int rowCounter = 0;
    unsigned short int i=0;
    unsigned short int j=0;

    for (i;i<3;i+=1)
    {
        for (j;j<3;j+=1)
        {
            //if grid[i][j]==checkingCharachter then rowCounter+=1
            rowCounter += (grid[i][j]==checkingCharachter)?1:0;
        }

        //if he has won in any row, return true
        if (rowCounter==3)
            return 1;

        rowCounter = 0;
        j=0;
    }

    return 0;
}

//This function checks whether or not the player has won in the cols
//------------------------------------------------------------------------------------------------------
_Bool isWinCols(char checkingCharachter)
{
    //checking the columns for win
    unsigned short int colCounter = 0;
    unsigned short int i=0;
    unsigned short int j=0;

    for (j;j<3;j+=1)
    {
        for (i;i<3;i+=1)
        {
            //if grid[i][j]==checkingCharachter then colCounter+=1
            colCounter += (grid[i][j]==checkingCharachter)?1:0;
        }

        if (colCounter==3)
            return 1;

        colCounter=0;
        i=0;
    }

    return 0;
}

//This function checks whether or not the player has won in the primal diagonal
//------------------------------------------------------------------------------------------------------
_Bool isWinPrimeDiags(char checkingCharachter)
{
    //checking the primary diagonal
    unsigned short int primDiagCounter = 0;
    unsigned short int i=0;
    unsigned short int j=0;

    for(i;i<3;i++)
    {
        for (j;j<3;j++)
        {
            //we are ony interested in primary diagonal where i=j
            if(i!=j)
                continue;
            //if grid[i][j]==checkingCharachter then primDiagCounter+=1
            primDiagCounter += (grid[i][j]==checkingCharachter)?1:0;
        }
        j=0;
    }
    if (primDiagCounter==3)
            return 1;
    return 0;
}


//This function checks whether or not the player has won in the secondary diagonal
//------------------------------------------------------------------------------------------------------
_Bool isWinSecDiags(char checkingCharachter)
{
    //checking the secondary diagonal
    unsigned short int secDiagCounter = 0;
    unsigned short int i=0;
    unsigned short int j=0;

    for(i;i<3;i++)
    {
        for (j;j<3;j++)
        {
            //we are only interested in cels where row+column = 2
            if(i+j!=2)
                continue;
            //if grid[i][j]==checkingCharachter then secDiagCounter+=1
            secDiagCounter += (grid[i][j]==checkingCharachter)?1:0;
        }
        j=0;
    }

    if (secDiagCounter==3)
        return 1;
    return 0;
}