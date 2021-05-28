#include "push_swap.h"

bool	stack_sorted(t_list *stack_a)
{
	while(stack_a->next)
	{
		if (*(int *)stack_a->content > *(int *)stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void    sort_stack(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc <= 3)
		solve_small(stack_a);
	else if (argc <= 5)
		solve_medium(stack_a, stack_b);
}

static	void	tmp_sort(int **arr, t_list *stack, int size)
{
	int		i;
	bool	sorted;
	int		tmp;

	i = 0;
	while (stack)
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

float	get_median(t_list *stack)
{
	float		median;
	int			*arr;
	int			stack_size;

	stack_size = ft_lstsize(stack);
	arr = malloc(sizeof(int) * (stack_size));
	tmp_sort(&arr, stack, stack_size);
	if (stack_size % 2 == 0)
		median = (arr[1] + arr[2]) / 2;
	else
		median = arr[2];
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