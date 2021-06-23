#include "push_swap.h"

void	solve_small(t_list **stack)
{
	int		max;

	if (ft_lstsize(*stack) == 2)
	{
		swap_stack(stack, "sa\n");
		return ;
	}
	max = get_highest(*stack);
	while (!stack_sorted(*stack, ft_lstsize(*stack)))
	{
		if (max == *(int *)(*stack)->next->next->content)
			swap_stack(stack, "sa\n");
		else if (max == *(int *)(*stack)->content)
			rotate_stack(stack, "ra\n");
		else
			rrotate_stack(stack, "rra\n");
	}
}

static	void	handle_b(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		if (stack_sorted(*stack_b, ft_lstsize(*stack_b)) && (*stack_b)->next)
			swap_stack(stack_b, "sb\n");
		else
			push_stack(stack_b, stack_a, "pa\n");
		if (!stack_sorted(*stack_a, ft_lstsize(*stack_a)))
			swap_stack(stack_a, "sa\n");
	}
}

void	solve_medium(t_list **stack_a, t_list **stack_b)
{
	float	median;

	median = get_median(*stack_a, ft_lstsize(*stack_a));
	while (!stack_sorted(*stack_a, ft_lstsize(*stack_a)))
	{
		if (*(int *)(*stack_a)->content < median)
			push_stack(stack_a, stack_b, "pb\n");
		else if (ft_lstsize(*stack_b) < 2 && ft_lstsize(*stack_a) > 3)
		{
			if (*(int *)(*stack_a)->next->content < median)
				rotate_stack(stack_a, "ra\n");
			else
				rrotate_stack(stack_a, "rra\n");
		}
		else
			solve_small(stack_a);
	}
	handle_b(stack_a, stack_b);
}

void	solve_large(t_list **stack_a, t_list **stack_b, int size)
{
	int	*chunks;
	int	i;

	i = 0;
	chunks = NULL;
	split_a(stack_a, stack_b, &chunks, size);
	if (chunks)
	{
		while (chunks[i] != -1)
			i++;
		while (i > 0)
		{
			handle_chunks(stack_a, stack_b, chunks[i - 1]);
			i--;
		}
		free(chunks);
	}
}
