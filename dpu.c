//    made by pawan kumar 1932

//    dpu -> dynamic printing ultra

//    used for making an animation effect of text like
//    (h, he, hel, hell, hello)

//    and it can also add colours in them by type colour's name.

//    syntax is simple -> dpu(sentence here, colour's name here, speed here);
//    more the speed more faster character apears.

//    available colours are -> red, green, blue, yellow, grey, orange, pink, cyan, black, white.

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int dpu(char*, char*, int);

int dpu(char *sentence, char *colour, int speed)
{
    // basic needed datatype, for loop
    int i;
    char clr[16];

    // protection from entering zero or negative at speed
    if(speed <= 0)
    {
        printf("speed can't be 0 or negative, change it to >= 1");
        return 1;
    }

    // calculation to convert speed into micro seconds
    speed = 1000000 / speed;

    // to convert colour string to lower case, using this method because colour is readable but not writable by behiviour
    for(i=0;colour[i]!='\0';i++)
    {
        clr[i]=colour[i];
        if(clr[i]>=65 && clr[i]<91)
        {
            clr[i]=clr[i]+32;
        }
    }

    // for colour i used colour leakage here
    if(strcmp(clr, "red") == 0) printf("\033[38;5;196m");
    else if(strcmp(clr, "green") == 0) printf("\033[32m");
    else if(strcmp(clr, "blue") == 0) printf("\033[34m");
    else if(strcmp(clr, "yellow") == 0) printf("\033[33m");
    else if(strcmp(clr, "grey") == 0) printf("\033[30m");
    else if(strcmp(clr, "orange") == 0) printf("\033[38;5;208m");
    else if(strcmp(clr, "pink") == 0) printf("\033[35m");
    else if(strcmp(clr, "cyan") == 0) printf("\033[36m");
    else if(strcmp(clr, "black") == 0) printf("\033[30m");
    else if(strcmp(clr, "white") == 0) printf("\033[37m");
    else { printf("invalid colour!"); return 1; }

    // main loop for render sentence's characters one by one
    for(i = 0; sentence[i] != '\0'; i++)
    {
        printf("%c", sentence[i]);
        fflush(stdout);
        usleep(speed);
    }

    // to stop colour leakage
    printf("\033[0m");
    return 0;
}