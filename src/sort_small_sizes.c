/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_sizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:07:57 by mjina             #+#    #+#             */
/*   Updated: 2024/04/16 15:07:58 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two_values(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three_values(t_stack **a)
{
	t_stack	*t_mid;
	int		bot;
	int		top;
	int		mid;

	t_mid = (*a)->next;
	top = (*a)->value;
	mid = t_mid->value;
	bot = t_mid->next->value;
	if (top > mid && bot > top)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (bot > mid && top > bot)
		ra(a);
	else if (mid > bot && bot > top)
	{
		sa(a);
		ra(a);
	}
	else if (mid > top && top > bot)
		rra(a);
}

void	sort_four_to_six_values(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;
	int	count;
	int	median;

	count = 0;
	median = get_stack_median(*a);
	transfer_median(a, b, median);
	size_a = get_stack_size(*a);
	size_b = get_stack_size(*b);
	if (size_a == 2)
		sort_two_values(a);
	else if (size_a == 3)
		sort_three_values(a);
	if (size_b == 2)
		reverse_sort_two_values(b);
	else if (size_b == 3)
		reverse_sort_three_values(b);
	while (count < size_b)
	{
		pa(a, b);
		count++;
	}
}

void	sort_small_sizes(t_stack **a, t_stack **b, int argc)
{
	if (argc == 3)
		sort_two_values(a);
	else if (argc == 4)
		sort_three_values(a);
	else if (argc >= 5 && argc <= 7)
		sort_four_to_six_values(a, b);
}
