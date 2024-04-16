/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:09:47 by mjina             #+#    #+#             */
/*   Updated: 2024/04/16 15:09:48 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new;

	new = new_stack(value);
	new->next = *stack;
	*stack = new;
}

void	reverse_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;
	t_stack	*next;

	prev = NULL;
	current = *stack;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*stack = prev;
}
