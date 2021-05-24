#include "push_swap.h"

static	bool    is_duplicate(int num, t_list *stack_a)
{
	while (stack_a)
	{
		if (num == *(int *)stack_a->content)
			return (true);
		stack_a = stack_a->next;
	}
	return (false);
}

//
bool    validate_input(char **argv, t_list **stack_a)
{
    int     i;
    long    *num;
	t_list	*new;

    i = 0;
    while (argv[++i])
    {
        if (ft_str_is_numeric(argv[i]))
        {
			num = malloc(sizeof(long));
			if (!num)
				return (false);
            *num = ft_atoi(argv[i]);
            if ((*num < INT_MIN || *num > INT_MAX) || is_duplicate(*num, *stack_a))
			{
				free(num);
                return (false);
			}
			new = ft_lstnew((int *)num);
			ft_lstadd_back(stack_a, new);
        }
        else
            return (false);
    }
    return (true);
}

