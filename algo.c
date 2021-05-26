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
	float median;

	median = get_median(*stack_a);
	while (!stack_sorted(*stack_a))
	{
		if (*(float *)(*stack_a)->content < median)
			push_stack(stack_a, stack_b, "pb");
		else if (ft_lstsize(*stack_b) < 2)
		{
			if (*(float *)(*stack_a)->next->content < median)
				rotate_stack(stack_a, "ra");
			else
				rrotate_stack(stack_a, "rra");
		}
		else
			solve_small(stack_a, 0);
	}
	while (*stack_b)
	{
		if (stack_sorted(*stack_b) && (*stack_b)->next)
			swap_stack(stack_b, "sb");
		else
			push_stack(stack_b, stack_a, "pa");
	}
}