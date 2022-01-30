/****************************************************************
*                                                               *
* Author            : Julian Proko (P16119)                     *
* Purpose           : C Programming Labs - O.S. bonus project 1 *
* Version           : 1.0                                       *
* Description       : Create processes and threads              *
* Date Created      : 30/31/2022                                *
* Last Modification : 30/31/2022                                *
*                                                               *
*****************************************************************/

//Proper library include
#include <stdio.h>      //Input - Output library
#include <sys/types.h>  //Primitive System Data Types
#include <sys/wait.h>   //Library Declaration for waiting
#include <unistd.h>     //Access to the POSIX Operating System API
#include <stdlib.h>     //General type and function related library
#include <pthread.h>    //Necessary library for thread creation
#include<time.h>        //Library for time - accessing (used in the srandom seed function)


int number=0;

/****************************************************************************
* Function responsible for increasing the global number variable by x value *
*****************************************************************************/
void change_number(int x)
{
  number += x;
}

/****************************************************************************
* Description:  Function of Thread 1                                        *
* Details:      The function increases its associate global number variable *
*               by a constant value of 5, using the change_number function. *
*****************************************************************************/
void *threadFunction1()
{
  long unsigned int threadID = pthread_self();
  //Size of threads stack
  size_t stksize;
  //Thread detached state
  int dtchedState;
  //Thread scope
  int scope;
  //Scheduling policy
  int policy;
  //Thread  attribute declaration
  pthread_attr_t atr;

  pthread_attr_getstacksize(&atr, &stksize);
  pthread_attr_getdetachstate(&atr, &dtchedState);
  pthread_attr_getscope(&atr, &scope);
  pthread_attr_getschedpolicy(&atr, &policy);
  printf("\nTHREAD 1 PROCESS ID: %lu : =========================\n", threadID);
  printf("THREAD 1 PROCESS ID: %lu : Invokation of thread\n", threadID);
  srand(time(0));
  int randomSleepNrSeconds = (rand()%5)+1+5;
  printf("THREAD 1 PROCESS ID: %lu : Sleep interval: %d ACTIVATED\n", threadID,randomSleepNrSeconds);
  sleep(randomSleepNrSeconds);
  printf("\nTHREAD 1 PROCESS ID: %lu : Sleep interval: TERMINATED\n", threadID);
  printf("THREAD 1 PROCESS ID: %lu : Increasing number by five (+=5)\n", threadID);
  change_number(5);
  printf("THREAD 1 PROCESS ID: %lu : Number result: %d\n", threadID, number);
  printf("THREAD 1 PROCESS ID: %lu : End of thread\n", threadID);
  printf("THREAD 1 PROCESS ID: %lu : Stack size in bytes = %lu\n", threadID, stksize);

  if(dtchedState == PTHREAD_CREATE_DETACHED)
  {
    printf("THREAD 1 PROCESS ID: %lu : Detached State = DETACHED\n", threadID);
  }
  else if(dtchedState == PTHREAD_CREATE_JOINABLE)
  {
    printf("THREAD 1 PROCESS ID: %lu : Detached State = JOINABLE\n", threadID);
  }
  else
  {
    printf("THREAD 1 PROCESS ID: %lu : Detached State = UNKNOWN\n", threadID);
  }

  if(scope == PTHREAD_SCOPE_SYSTEM)
  {
    printf("THREAD 1 PROCESS ID: %lu : Thread Scope = SYSTEM\n", threadID);
  }
  else if (scope == PTHREAD_SCOPE_PROCESS)
  {
    printf("THREAD 1 PROCESS ID: %lu : Thread Scope = PROCESS\n", threadID);
  }
  else
  {
    printf("THREAD 1 PROCESS ID: %lu : Thread Scope = UNKNOWN\n", threadID);
  }

  if (policy == SCHED_FIFO)
  {
    printf("THREAD 1 PROCESS ID: %lu : Scheduling Policy = First In First Out\n", threadID);
  }
  else if (policy == SCHED_RR)
  {
    printf("THREAD 1 PROCESS ID: %lu : Scheduling Policy = Round Robin\n", threadID);
  }
  else if (policy ==SCHED_OTHER)
  {
    printf("THREAD 1 PROCESS ID: %lu : Scheduling Policy = Default - Other\n", threadID);
  }
  else
  {
    printf("THREAD 1 PROCESS ID: %lu : Scheduling Policy = Unknown\n", threadID);
  }
  printf("THREAD 1 PROCESS ID: %lu :=========================\n", threadID);
  pthread_exit(NULL);
}

/****************************************************************************
* Description:  Function of Thread 2                                        *
* Details:      The function decreases its associate global number variable *
*               by a constant value of x \in [1,10], by the use of          *
*               change_number function. The x value is generated randomly.  *
*****************************************************************************/
void *threadFunction2()
{
  long unsigned int threadID = pthread_self();
  //Size of threads stack
  size_t stksize;
  //Thread detached state
  int dtchedState;
  //Thread scope
  int scope;
  //Scheduling policy
  int policy;
  //Thread  attribute declaration
  pthread_attr_t atr;

  pthread_attr_getstacksize(&atr, &stksize);
  pthread_attr_getdetachstate(&atr, &dtchedState);
  pthread_attr_getscope(&atr, &scope);
  pthread_attr_getschedpolicy(&atr, &policy);
  printf("\nTHREAD 2 PROCESS ID: %lu : =========================\n", threadID);
  printf("THREAD 2 PROCESS ID: %lu : Invokation of thread\n", threadID);
  srand(time(0));
  int randomSleepNrSeconds = (rand()%5)+1+5;
  printf("THREAD 2 PROCESS ID: %lu : Sleep interval: %d ACTIVATED\n", threadID,randomSleepNrSeconds);
  sleep(randomSleepNrSeconds);
  printf("\nTHREAD 2 PROCESS ID: %lu : Sleep interval: TERMINATED\n", threadID);
  int randomDecreaseNr = (rand()%10)+1;
  printf("THREAD 2 PROCESS ID: %lu : Decreasing number by (-=%d)\n", threadID, randomDecreaseNr);
  change_number((-1)*randomDecreaseNr);
  printf("THREAD 2 PROCESS ID: %lu : Number result: %d\n", threadID, number);
  printf("THREAD 2 PROCESS ID: %lu : End of thread\n", threadID);
  printf("THREAD 2 PROCESS ID: %lu : Stack size in bytes = %lu\n", threadID, stksize);
  if(dtchedState == PTHREAD_CREATE_DETACHED)
  {
    printf("THREAD 2 PROCESS ID: %lu : Detached State = DETACHED\n", threadID);
  }
  else if(dtchedState == PTHREAD_CREATE_JOINABLE)
  {
    printf("THREAD 2 PROCESS ID: %lu : Detached State = JOINABLE\n", threadID);
  }
  else
  {
    printf("THREAD 2 PROCESS ID: %lu : Detached State = UNKNOWN\n", threadID);
  }

  if(scope == PTHREAD_SCOPE_SYSTEM)
  {
    printf("THREAD 2 PROCESS ID: %lu : Thread Scope = SYSTEM\n", threadID);
  }
  else if (scope == PTHREAD_SCOPE_PROCESS)
  {
    printf("THREAD 2 PROCESS ID: %lu : Thread Scope = PROCESS\n", threadID);
  }
  else
  {
    printf("THREAD 2 PROCESS ID: %lu : Thread Scope = UNKNOWN\n", threadID);
  }

  if (policy == SCHED_FIFO)
  {
    printf("THREAD 2 PROCESS ID: %lu : Scheduling Policy = First In First Out\n", threadID);
  }
  else if (policy == SCHED_RR)
  {
    printf("THREAD 2 PROCESS ID: %lu : Scheduling Policy = Round Robin\n", threadID);
  }
  else if (policy ==SCHED_OTHER)
  {
    printf("THREAD 2 PROCESS ID: %lu : Scheduling Policy = Default - Other\n", threadID);
  }
  else
  {
    printf("THREAD 2 PROCESS ID: %lu : Scheduling Policy = Unknown\n", threadID);
  }
  printf("THREAD 2 PROCESS ID: %lu :=========================\n", threadID);
  pthread_exit(NULL);
}

/*****************************************************************************
* Function responsible for the functionality of parent process, upon fork     *
******************************************************************************/
void parentFunction()
{
  int processID = getpid();
  printf("PARENTS PROCESS ID: %d : Initiating execution..\n", processID);
  printf("PARENTS PROCESS ID: %d : Process is going to wait for child process via => wait(NULL) sysCall invokation.\n", processID);
  wait(NULL);
  printf("\nPARENTS PROCESS ID: %d : Final number result equals to: %d\n", processID, number);
  printf("PARENTS PROCESS ID: %d : Process exits.\n", processID);
  exit(0);
}

/*****************************************************************************
* Function responsible for the functionality of child process, upon fork     *
******************************************************************************/
void childFunction()
{
  int processID = getpid();
  printf("\nCHILD PROCESS ID: %d : =========================\n",processID);
  printf("CHILD PROCESS ID: %d : Initiating execution.\n",processID);

  //A reference table to the IDs of the 2 threads needed.
  pthread_t id[2];

  //Create 2 threads for diffrent tasks
  int fiveValue = 5;
  pthread_create(&id[0], NULL, threadFunction1, NULL);
  pthread_create(&id[1], NULL, threadFunction2, NULL);
  printf("CHILD PROCESS ID: %d : Wait for thread execution via => pthread_join(threadID,NULL) sysCall invokation.\n", processID);
  pthread_join(id[0],NULL);
  pthread_join(id[1],NULL);

  printf("\nCHILD PROCESS ID: %d : Final Number equals to %d.\n", processID, number);
  printf("CHILD PROCESS ID: %d : Process exits.\n", processID);
  printf("CHILD PROCESS ID: %d : =========================\n", processID);
  exit(1);
}


int main()
{
  //By this line, the main programm process, is forked into 2 paralel running processes.
  //The main program is called the parent while the secondary program is called the child processes
  // => childPID variable holds the process ID of the child function
  //Given that it is the first fork performed in the programm, we expect a process ID = 0
  pid_t childPID = fork();

  if(childPID == -1)
  {
    //This case is invoked uppon fork not succesfully performed
    printf("Unfortunately, fork was not succesfully performed.\n");
  }
  else if(childPID == 0)
  {
    //This case is invoked uppon fork succesfully performed
    //The code executed by this branch, is the child process code
    childFunction();
  }
  else
  {
    //This case is invoked uppon fork succesfully performed
    //The code executed by this branch, is the parent process code
    parentFunction();
  }
  return 0;
}
