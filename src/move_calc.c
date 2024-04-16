/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:04:57 by mjina             #+#    #+#             */
/*   Updated: 2024/04/16 15:04:58 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_closest_move(int i, int size)
{
	if (i <= size / 2)
		return (i);
	return (i - size);
}

int	get_position_in_a(int val, t_stack *a)
{
	int		i;
	int		size_a;
	int		stack_min;
	t_stack	*tmp;
	t_stack	*prev;

	i = get_stack_max_elem(a);
	tmp = a->next;
	prev = a;
	size_a = get_stack_size(a);
	stack_min = get_stack_min_elem(a);
	if (val > i)
		return (get_closest_move(get_stack_val_index(a, i), size_a) + 1);
	if (val < stack_min)
		return (get_closest_move(get_stack_val_index(a, stack_min), size_a));
	i = 1;
	while (tmp)
	{
		if (tmp->value > val && prev->value < val)
			return (get_closest_move(i, size_a));
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	return (get_closest_move(i, size_a));
}

t_move_price	*get_move_price(t_stack *a, t_stack *b, int *t_size)
{
	t_stack			*tmp;
	t_move_price	*ret;
	int				b_size;
	int				i;

	b_size = get_stack_size(b);
	i = 0;
	tmp = b;
	ret = malloc(sizeof(t_move_price) * b_size);
	while (tmp)
	{
		ret[i].value = tmp->value;
		ret[i].move_count[0] = get_position_in_a(tmp->value, a);
		if (i <= b_size / 2)
			ret[i].move_count[1] = i;
		else
			ret[i].move_count[1] = i - b_size;
		tmp = tmp->next;
		i++;
	}
	*t_size = b_size;
	return (ret);
}

int	pick_best_move(t_move_price *t, int t_size)
{
	int	i;
	int	best;
	int	moves_best;
	int	cm;

	i = 0;
	best = -1;
	moves_best = INT_MAX;
	cm = 0;
	while (i < t_size)
	{
		if (t[i].move_count[0] * t[i].move_count[1] > 0)
			cm = max(abs(t[i].move_count[0]), abs(t[i].move_count[1]));
		else
			cm = abs(t[i].move_count[0]) + abs(t[i].move_count[1]);
		if (cm < moves_best)
		{
			best = i;
			moves_best = cm;
		}
		i++;
	}
	return (best);
}
