#include "../push_swap.h"

int get_stack_val_index(t_stack *stack, int val)
{
    int     i;
    t_stack *tmp;

    if (!stack)
        return (-1);
    i = 0;
    tmp = stack;
    while (tmp != NULL)
    {
        if (tmp->value == val)
            break;
        tmp = tmp->next;
        i++;
    }
    return (i);
}

void    parse(t_stack **a, int argc, char **argv)
{
    int     i;
    long    num;

    i = argc - 1;
    while (i >= 1)
    {
        num = ft_atoi_long(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            errored(a);
        add_to_stack(a, (int)num);
        i--;
    }
}

void    reverse_parse(t_stack **a, char *argv)
{
    char **splitted_argv;
    int i;
    int num;

    splitted_argv = ft_split(argv, ' ');
    i = 0;
    while (splitted_argv[i])
    {
        num = ft_atoi_long(splitted_argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            errored(a);
        add_to_stack(a, (int)num);
        i++;
    }
    reverse_stack(a);
    double_free(splitted_argv, i);
}

t_stack *init_stack_a(int argc, char **argv)
{
    t_stack *a;

    if (!(check_is_integer(argc, argv)) || argc < 2)
    {
        ft_putstr_fd("Error\n", 2);
        exit(0);
    }
    a = NULL;
    if (argc == 2)
        reverse_parse(&a, argv[1]);
    else
        parse(&a, argc, argv);
    if (check_duplicates_in_stack(a))
        errored(&a);
    if (check_sorted(a))
        errored_without_notice(&a);
    return (a);
}
