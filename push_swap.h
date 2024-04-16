#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_move_price
{
	int	move_count[2];
	int	value;
}	t_move_price;

void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			swap(t_stack **stack);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack **b);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rotate(t_stack **stack);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			reverse_rotate(t_stack **stack);
void			bubble_sort(int *arr, int n);
void			parse(t_stack **a, int argc, char **argv);
void			reverse_parse(t_stack **a, char *argv);
void	    	move_list_to_b(t_stack **a, t_stack **b);
void	    	transfer_median(t_stack **a, t_stack **b, int median);
void		    reverse_sort_two_values(t_stack **b);
void		    reverse_sort_three_values(t_stack **b);
void		    pick_sub(t_move_price *t, t_stack **a, t_stack **b);
void		    pick_move(t_move_price t, t_stack **a, t_stack **b);
void		    sort_big_sizes(t_stack **a, t_stack **b);
void		    sort_two_values(t_stack **a);
void			sort_three_values(t_stack **a);
void			sort_four_to_six_values(t_stack **a, t_stack **b);
void			sort_small_sizes(t_stack **a, t_stack **b, int argc);
void			errored(t_stack **a);
void			errored_without_notice(t_stack **a);
void		    free_stack(t_stack **stack);
void		    double_free(char **ptr, size_t size);
void			free_multiple(int n, ...);
void			put_min_element_on_top(t_stack **stack);
void		    add_to_stack(t_stack **stack, int value);
void		    reverse_stack(t_stack **stack);
long			ft_atoi_long(const char *str);
int				check_is_integer(int argc, char **argv);
int				*stack_to_array(t_stack *stack);
int				get_stack_size(t_stack *stack);
int				get_stack_median(t_stack *stack);
int				get_stack_val_index(t_stack *stack, int val);
int				int_in_arr(int n, int *arr, int size);
int				min(int a, int b);
int 			max(int a, int b);
int 			abs(int a);
int				get_closest_move(int i, int size);
int 			get_position_in_a(int val, t_stack *a);
int				pick_best_move(t_move_price *t, int t_size);
int				check_duplicates(t_stack *stack, int val);
int				check_duplicates_in_stack(t_stack *stack);
int				check_sorted(t_stack *stack);
int				get_stack_min_elem(t_stack *stack);
int				get_stack_max_elem(t_stack *stack);
int				*get_list(int *arr, int size, int *list_size, int i);
int				*list_sub(int size, int list_len, int *arr, int *index);
// static int		search_replace(int *list, int left, int right, int key);
t_stack			*init_stack_a(int argc, char **argv);
t_stack			*copy_stack(t_stack *src);
t_stack			*new_stack(int value);
t_move_price    *get_move_price(t_stack *a, t_stack *b, int *t_size);

#endif