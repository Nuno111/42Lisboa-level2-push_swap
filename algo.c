#include "push_swap.h"

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

void	solve_medium(t_list **stack_a, t_list **stack_b)
{
	int median;

	median = get_median(stack_a);
	while (!stack_sorted && *stack_b != NULL)
	{
		if (stack_sorted)
		{
			push_stack(stack_b, stack_a, "pa");

		}
		if (*(int *)(*stack_a)->content < median)
			push_stack(stack_a, stack_b, "pb");

	}
}
