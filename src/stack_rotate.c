/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:11:08 by mjina             #+#    #+#             */
/*   Updated: 2024/04/16 15:11:09 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*i;

	if (!stack)
		return ;
	if (!(*stack)->next)
		return ;
	tmp = *stack;
	i = *stack;
	*stack = tmp->next;
	while (i->next != NULL)
		i = i->next;
	i->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
