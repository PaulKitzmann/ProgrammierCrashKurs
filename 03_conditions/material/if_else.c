#include <stdio.h>

int main()
{

    int cond1 = 1 != 2; // True
    int cond2 = 1 > 2; // False

    // if (cond1)
    // {
    //     printf("cond1 is True\n");
    // }

    // if (cond2)
    // {
    //     printf("cond2 is True\n");
    // }
    // else
    // {
    //     printf("cond2 is False\n");
    // }


    int a = 2;
    if (a == 1)
    {
        printf("a is 1\n");
    }
    else if (a == 2)
    {
        printf("a is 2\n");
    }
    else if (a == 3)
    {
        printf("a is 3\n");
    }
    else
    {
        printf("a is something else\n");
    }

    return 0;
}