/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   stack_free.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mjina <marvin@42.fr>					   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/16 15:08:37 by mjina			 #+#	#+#			 */
/*   Updated: 2024/04/16 15:08:38 by mjina			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*stack = NULL;
}

void	double_free(char **ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_multiple(int n, ...)
{
	va_list	args;
	int		i;
	void	*p;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		p = va_arg(args, void *);
		free(p);
		i++;
	}
	va_end(args);
}
