/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:02:53 by mjina             #+#    #+#             */
/*   Updated: 2024/04/16 15:02:54 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	abs(int a)
{
	if (a >= 0)
		return (a);
	return (a * (-1));
}
