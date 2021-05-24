#include "push_swap.h"

int		highest_nbr(t_list *stack)
{
	int max;

	max = 0;
	while(stack)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

void    solve_small(t_list **stack, int argc)
{
	int		max;

    if (argc == 2)
	{
        swap_stack(stack, "sa");
		return ;
	}
	max = highest_nbr(*stack);
	while (!stack_sorted(*stack))
	{
		if (max == *(int *)(*stack)->next->next->content)
			swap_stack(stack, "sa");
		else
			rrotate_stack(stack, "rra");
	}
}
