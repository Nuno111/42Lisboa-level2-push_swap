#include "push_swap.h"

void	split_a(t_list **stack_a, t_list **stack_b, int size, int *chunks)
{
	if (size == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			swap_stack(stack_a, "sa");
		return ;
	}
	else if (size == 1)
		return ;
	push_to_b(stack_a, stack_a, size);
	add_to_chunks(chunks, size);
	split_a(stack_a, stack_b, size / 2, chunks);
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int size)
{
	float	median;
	int		ra_count;

	median = get_median(stack_a, size);
	ra_count = 0;
	while (size > 0)
	{
		if (*(int *)(*stack_a)->content < median)
		{
			push_stack(stack_a, stack_b, "pb");
			size--;
		}
		else
		{
			rotate_stack(stack_a, "ra");
			ra_count++;
		}
	}
	while (ra_count > 0)
	{
		rrotate_stack(stack_a, "rra");
		ra_count--;
	}
}
