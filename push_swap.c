/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:58:16 by mjina             #+#    #+#             */
/*   Updated: 2024/04/16 14:58:19 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack_a(argc, argv);
	b = NULL;
	sort_small_sizes(&a, &b, argc);
	sort_big_sizes(&a, &b);
	free_stack(&a);
	return (0);
}
