#include "push_swap.h"

void    solve_small(t_list **stack)
{
	int		max;

    if (ft_lstsize(*stack) == 2)
	{
        swap_stack(stack, "sa");
		return ;
	}
	max = get_highest(*stack);
	while (!stack_sorted(*stack))
	{
		if (max == *(int *)(*stack)->next->next->content)
			swap_stack(stack, "sa");
		else if (max == *(int *)(*stack)->content)
			rotate_stack(stack, "ra");
		else
			rrotate_stack(stack, "rra");
	}
}

void	solve_medium(t_list **stack_a, t_list **stack_b)
{
	float	median;

	median = get_median(*stack_a);
	while (!stack_sorted(*stack_a))
	{
		if (*(int *)(*stack_a)->content < median)
			push_stack(stack_a, stack_b, "pb");
		else if (ft_lstsize(*stack_b) < 2 && ft_lstsize(*stack_a) > 3)
		{
			if (*(int *)(*stack_a)->next->content < median)
				rotate_stack(stack_a, "ra");
			else
				rrotate_stack(stack_a, "rra");
		}
		else
			solve_small(stack_a);
	}
	while (*stack_b)
	{
		if (stack_sorted(*stack_b) && (*stack_b)->next)
			swap_stack(stack_b, "sb");
		else
			push_stack(stack_b, stack_a, "pa");
		if (!stack_sorted(*stack_a))
			swap_stack(stack_a, "sa");
	}
}
