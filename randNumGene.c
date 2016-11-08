#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define BOUND 10000
int main()
{
    int i, j;
    srand((unsigned)time(NULL));
    scanf("%d", &j);
    for (i=0; i<j; ++i)
        printf("%d ", rand() % BOUND + 1);
    putchar('\n');
    return 0;
}

