#include "push_swap.h"

int		par_or_impar(int size)
{
	if (size % 2 == 0)
		return (size / 2);
	return (size / 2 + 1);
}

void	handle_chunks(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 1)
	{
		push_stack(stack_b, stack_a, "pa");
		return ;
	}
	else if (size == 2)
	{
		if (stack_sorted(*stack_b, size))
			swap_stack(stack_b, "sb");
		push_stack(stack_b, stack_a, "pa");
		push_stack(stack_b, stack_a, "pa");
		return ;
	}
	push_to_a(stack_b, stack_a, size);
	if (!stack_sorted(*stack_a, ft_lstsize(*stack_a)))
		solve_large(stack_a, stack_b, par_or_impar(size));
	if (*stack_b)
		handle_chunks(stack_a, stack_b, par_or_impar(size));
}

void	save_chunks_size(int **chunks, int size)
{
	int	*new_chunk;
	int	*new_arr;
	int	arr_size;
	int	i;

	i = 0;
	new_arr = NULL;
	new_chunk = NULL;
	if (*chunks)
	{
		arr_size = 0;
		while (chunks[0][arr_size] != -1)
			arr_size++;
		arr_size += 2;
		new_arr = malloc(sizeof(int) * arr_size);
		if (!new_arr)
			return ;
		while (i + 2 != arr_size)
		{
			new_arr[i] = chunks[0][i];
			i++;
		}
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

void	push_to_a(t_list **stack_b, t_list **stack_a, int size)
{
	float	median;
	int		ra_count;

	median = get_median(*stack_b, size);
	ra_count = 0;
	size /= 2;
	while (size > 0)// && !stack_sorted(*stack_b, ft_lstsize(*stack_b)))
	{
		if (*(int *)(*stack_b)->content > median)
		{
			push_stack(stack_b, stack_a, "pa");
			size--;
		}
		else
		{
			rotate_stack(stack_b, "rb");
			ra_count++;
		}
	}
	while (ra_count > 0) //&& !stack_sorted(*stack_b, ft_lstsize(*stack_b)))
	{
		rrotate_stack(stack_b, "rrb");
		ra_count--;
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int size)
{
	float	median;
	int		ra_count;

	median = get_median(*stack_a, size);
	ra_count = 0;
	size /= 2;
	while (size > 0)// && !stack_sorted(*stack_a, ft_lstsize(*stack_a)))
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
	while (ra_count > 0)// && !stack_sorted(*stack_a, ft_lstsize(*stack_a)))
	{
		rrotate_stack(stack_a, "rra");
		ra_count--;
	}
}

void	split_a(t_list **stack_a, t_list **stack_b, int **chunks, int size)
{
	if (size == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			swap_stack(stack_a, "sa");
		return ;
	}
	else if (size == 1)
		return ;
	push_to_b(stack_a, stack_b, size);
	save_chunks_size(chunks, size / 2);
	split_a(stack_a, stack_b, chunks, par_or_impar(size));
}
