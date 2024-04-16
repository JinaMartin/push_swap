#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	*b = tmp_b->next;
	*a = tmp_b;
	tmp_b->next = tmp_a;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	*a = tmp_a->next;
	*b = tmp_b;
	tmp_b->next = tmp_b;
	ft_printf("pb\n");
}