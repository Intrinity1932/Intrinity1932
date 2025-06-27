//made by pawan kumar 1932

// use for clean whole screen at once

#include <stdio.h>


int erase_screen();

int erase_screen()
{
    // unicode for most of terminals, not usable for code blocks or tyrbo c. only for modern terminals
        printf("\033[H\033[J");
        fflush(stdout);


    return 0;
}