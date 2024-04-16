/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   median_operation.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mjina <marvin@42.fr>					   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/16 15:03:18 by mjina			 #+#	#+#			 */
/*   Updated: 2024/04/16 15:03:19 by mjina			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../push_swap.h"

void	transfer_median(t_stack **a, t_stack **b, int median)
{
	int	size;
	int	i;

	size = get_stack_size(*a);
	i = 1;
	while (i <= size)
	{
		if ((*a)->value < median)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}
