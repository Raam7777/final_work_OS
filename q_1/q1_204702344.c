#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. BSS */
int primes[] = { 2, 3, 5, 7 };  /* 2. initialized data section */

static int
square(int x)                   /* 3. text (code) section */
{
    int result;                 /* 4. stack */

    result = x * x;
    return result;              /* 5. cpu register */
}

static void
doCalc(int val)                 /* 6. text (code) section */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7. not allocated-because we didnt use it */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* text (code) section */
{
    static int key = 9973;      /* initialized data section */
    static char mbuf[10240000]; /* BSS */
    char* p;                    /* not allocated-because we didnt use it */


    doCalc(key);

    exit(EXIT_SUCCESS);
}
