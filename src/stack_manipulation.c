#include "../push_swap.h"

int	get_stack_min_elem(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_stack_max_elem(t_stack *stack)
{
	t_stack *tmp;
	int		min;

	tmp = stack;
	min = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	put_min_element_on_top(t_stack **stack)
{
	int	min_elem;
	int	ind;
	int	stack_size;
	int	i;

	min_elem = get_stack_min_elem(*stack);
	ind = get_stack_val_index(*stack, min_elem);
	stack_size = get_stack_size(*stack);
	i = 0;
	if (ind > stack_size / 2)
	{
		while (i < stack_size - ind)
		{
			reverse_rotate(stack);
			i++;
		}
	}
	else
	{
		while (i < ind)
		{
			reverse_rotate(stack);
			i++;
		}
	}
}

t_stack	*copy_stack(t_stack *src)
{
	t_stack	*dest;
	t_stack	*tmp;

	dest = NULL;
	if (!src)
		return (NULL);
	tmp = src;
	while (tmp != NULL)
	{
		add_to_stack(&dest, tmp->value);
		tmp = tmp->next;
	}
	reverse_stack(&dest);
	return (dest);
}
