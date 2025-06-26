// maded by pawan kumar

// use for make dynamic like effects in pure c

// only for linux based terminals

#include <stdio.h>
#include <unistd.h>

// timer for second based breaks
int timer(int);

//advance_timer for micro second based breaks
// float is use means time can be from infinite second to .0000001 seconds
int advance_timer(double);






//use for direct single second to many second breaks
int timer(int second)
{

    // protection

    if(second>0)
    {
    sleep(second);}
    else{
            printf("second can't be zero or less than zero");
    }

    return 0;
}




// use for second to micro second level breaks
int advance_timer(double second)
{

    if(second<0.0 || second>0.0)
    {
    double micro_seconds;

    // sconds to micro second coverter
    micro_seconds=second*1000000;


    usleep(micro_seconds);
    }
    else{
            printf("second can't be zero");
    }

    return 0;
}