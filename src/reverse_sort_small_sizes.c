#include "../push_swap.h"

void    reverse_sort_two_values(t_stack **b)
{
    if ((*b)->value < (*b)->next->value)
        sb(b);
}

void    reverse_sort_three_values(t_stack **b)
{
    t_stack *t_mid;
    int     bot;
    int     top;
    int     mid;

    t_mid = (*b)->next;
    top = (*b)->value;
    mid = t_mid->value;
    bot = t_mid->next->value;
    if (top < mid && bot < top)
        sb(b);
    else if (top < mid && mid < bot)
    {
        sb(b);
        rrb(b);
    }
    else if (bot < mid && top < bot)
        rb(b);
    else if (mid < bot && bot < top)
    {
        sb(b);
        rb(b);
    }
    else if (mid < top && top < bot)
        rrb(b);
}
