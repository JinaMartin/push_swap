#include "../push_swap.h"

int min(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

int max(int a, int b)
{
    if (a < b)
        return (b);
    return (a);
}

int abs(int a)
{
    if (a < 0)
        a = a * (-1);
    return (a);
}
