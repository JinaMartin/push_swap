/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   big_size_utils.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mjina <marvin@42.fr>					   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/16 14:59:23 by mjina			 #+#	#+#			 */
/*   Updated: 2024/04/16 14:59:26 by mjina			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../push_swap.h"

static int	search_replace(int *list, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (list[mid] > key)
			right = mid - 1;
		else if (list[mid] == key)
			return (mid);
		else if (mid + 1 <= right && list[mid + 1] >= key)
		{
			list[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		list[mid] = key;
		return (mid);
	}
	list[mid + 1] = key;
	return (mid + 1);
}

int	*list_sub(int size, int list_len, int *arr, int *index)
{
	int	i;
	int	tmp;
	int	*num;

	num = (int *)malloc((list_len + 2) * sizeof(int));
	i = size - 1;
	tmp = list_len;
	while (i >= 0)
	{
		if (index[i] == tmp)
			num[tmp--] = arr[i];
		i--;
	}
	return (num);
}

int	int_in_arr(int n, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	*get_list(int *arr, int size, int *list_size, int i)
{
	int	list_len;
	int	*ans;
	int	*list;
	int	*index;

	list_len = -1;
	list = (int *)malloc(sizeof(int) * size);
	index = (int *)malloc(sizeof(int) * size);
	list[0] = arr[0];
	i = 1;
	while (i < size)
		list[i++] = INT_MAX;
	i = 1;
	while (i < size)
	{
		index[i] = search_replace(list, 0, i, arr[i]);
		if (list_len < index[i])
			list_len = index[i];
		i++;
	}
	ans = list_sub(size, list_len, arr, index);
	*list_size = list_len + 1;
	free_multiple(2, list, index);
	return (ans);
}

void	move_list_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*list;
	int		list_size;
	int		i;
	int		*arr;

	tmp = copy_stack(*a);
	put_min_element_on_top(&tmp);
	arr = stack_to_array(tmp);
	list = get_list(&arr[1], arr[0], &list_size, 0);
	arr[0] = get_stack_size(*a);
	i = 1;
	while (i <= arr[0])
	{
		if (int_in_arr((*a)->value, list, list_size))
			ra(a);
		else
			pb(a, b);
		i++;
	}
	free_stack(&tmp);
	free_multiple(2, arr, list);
}
