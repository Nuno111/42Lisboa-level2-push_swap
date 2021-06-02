#include "push_swap.h"

bool	stack_sorted(t_list *stack, int size)
{
	while (size > 1)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (false);
		stack = stack->next;
		size--;
	}
	return (true);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc <= 3)
		solve_small(stack_a);
	else if (argc <= 5)
		solve_medium(stack_a, stack_b);
	else
		solve_large(stack_a, stack_b, argc);
}

int	par_or_impar(int size)
{
	if (size % 2 == 0)
		return (size / 2);
	return (size / 2 + 1);
}

void	realloc_chunks(int **chunks, int size)
{
	int	arr_size;
	int	*new_arr;
	int	i;

	i = 0;
	arr_size = 0;
	new_arr = NULL;
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

void	save_chunks_size(int **chunks, int size)
{
	int	*new_chunk;

	new_chunk = NULL;
	if (*chunks)
		realloc_chunks(chunks, size);
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
