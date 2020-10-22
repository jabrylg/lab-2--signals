#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "timer.h"

int global = 0;
const int ALARM_CONST = 1;

void handler(int signum)
{ //signal handler
    printf("Hello World!\n");
    global = 1;
    alarm(ALARM_CONST);
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, handler); //uses a registered handler to handle the SIGALRM
    alarm(ALARM_CONST);       //schedule a SIGALRM for the same amount of time as the alarm constant

    while (ALARM_CONST)
    {
        while (global == 0); //loop that does not terminate
        
        printf("Turing was right!");
        printf("\n");
        global = 0;
        counter();
       // signal(SIGINT, sigint_handler);
    };
}