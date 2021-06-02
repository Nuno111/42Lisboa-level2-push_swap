#include "push_swap.h"

bool	stack_sorted(t_list *stack, int size)
{
	while(size > 1)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (false);
		stack = stack->next;
		size--;
	}
	return (true);
}

void    sort_stack(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc <= 3)
		solve_small(stack_a);
	else if (argc <= 5)
		solve_medium(stack_a, stack_b);
	else
		solve_large(stack_a, stack_b, argc);
}

static	void	tmp_sort(int **arr, t_list *stack, int size)
{
	int		i;
	bool	sorted;
	int		tmp;

	i = 0;
	while (i < size)
	{
		(*arr)[i] = *(int *)stack->content;
		i++;
		stack = stack->next;
	}
	sorted = false;
	while (!sorted)
	{
		i = 0;
		sorted = true;
		while (i < size - 1)
		{
			if ((*arr)[i] > (*arr)[i + 1])
			{
				tmp = (*arr)[i];
				(*arr)[i] = (*arr)[i + 1];
				(*arr)[i + 1] = tmp;
				sorted = false;
			}
			i++;
		}
	}
}

float	get_median(t_list *stack, int size)
{
	float		median;
	int			*arr;

	arr = malloc(sizeof(int) * (size));
	tmp_sort(&arr, stack, size);
	if (size % 2 == 0)
		median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
	else
		median = arr[size / 2];
	free(arr);
	return (median);
}

int	get_highest(t_list *stack)
{
	int max;

	max = INT_MIN;
	while(stack)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

int	get_smallest(t_list *stack)
{
	int min;

	min = INT_MAX;
	while(stack)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}
