#include "../push_swap.h"

void    transfer_median(t_stack **a, t_stack **b, int median)
{
    int size;
    int i;

    size = get_stack_size(*a);
    i = 1;
    while (i <= size)
    {
        if ((*a)->value < median)
            pb(a, b);
        else
            ra(a);
        i++;
    }
}
