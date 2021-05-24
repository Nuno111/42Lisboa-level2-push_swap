#include "push_swap.h"

int		highest_nbr(t_list *stack)
{
	int max;

	max = 0;
	while(stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

void    solve_small(t_list **stack, int argc)
{
	t_list	*mid;
	int		max;

    if (argc == 2)
	{
        swap_stack(stack, "sa");
		return ;
	}
	max = highest_nbr(*stack);
	while (!stack_sorted(*stack))
	{
		if (max == (*stack)->next->next->content)
			swap_stack(stack, "sa");
		else
			rotate_stack(stack, "ra");
	}
}
