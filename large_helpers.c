#include "push_swap.h"

void	save_chunks_size(int **chunks, int size)
{
	int	*new_chunk;
	int	*new_arr;
	int	arr_size;

	new_arr = NULL;
	new_chunk = NULL;
	if (*chunks)
	{
		arr_size = 0;
		while (chunks[0][arr_size] != -1)
			arr_size++;
		arr_size =+ 2;
		new_arr = malloc(sizeof(int) * arr_size);
		if (!new_arr)
			return ;
		ft_memmove(new_arr, *chunks, sizeof(int) * (arr_size - 2));
		new_arr[arr_size - 2] = size;
		new_arr[arr_size - 1] = -1;
		free(*chunks);
		*chunks = new_arr;
	}
	else
	{
		new_chunk = malloc(sizeof(int) * 2);
		if (!new_chunk)
			return ;
		new_chunk[0] = size;
		new_chunk[1] = -1;
		*chunks = new_chunk;
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int size)
{
	float	median;
	int		ra_count;

	median = get_median(*stack_a, size);
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

void	split_a(t_list **stack_a, t_list **stack_b, int size, int **chunks)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			swap_stack(stack_a, "sa");
		return ;
	}
	else if (stack_size == 1)
		return ;
	push_to_b(stack_a, stack_b, size);
	save_chunks_size(chunks, size);
	split_a(stack_a, stack_b, (stack_size - size) / 2, chunks);
}
