#include "../push_swap.h"

void    reverse_rotate(t_stack **stack)
{
    t_stack *prev;
    t_stack *i;

    if (!stack)
        return ;
    if (!(*stack)->next)
        return ;
    i = *stack;
    while (i->next)
    {
        prev = i;
        i = i->next;
    }
    prev->next = NULL;
    i->next = *stack;
    *stack = i;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr");
}