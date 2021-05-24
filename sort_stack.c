#include "push_swap.h"

bool	stack_sorted(t_list *stack_a)
{
	while(stack_a->next)
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void    sort_stack(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc <= 3)
		solve_small(stack_a, argc);
	/*
	else if (argc <= 5)
		solve_medium(stack_a, stack_b);
	else
		solve_large(stack_a, stack_b);
	*/
}
