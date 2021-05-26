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
		solve_small(stack_a, argc);
	else if (argc <= 5)
		solve_medium(stack_a, stack_b);
}

static	t_list	*list_sort(t_list *stack)
{
	bool	sorted;
	t_list	*tmp;
	int		val;

	sorted = false;
	while (!sorted)
	{
		tmp = stack;
		sorted = true;
		while (tmp->next)
		{
			if (*(int *)tmp->content > *(int *)tmp->next->content)
			{
				val = *(int *)tmp->content;
				*(int *)tmp->content = *(int *)tmp->next->content;
				*(int *)tmp->next->content = val;
				sorted = false;
			}
			tmp = tmp->next;
		}
	}
	return (stack);
}

float	get_median(t_list *stack)
{
	t_list		*sorted;
	float		median;

	sorted = list_sort(stack);
	if (ft_lstsize(sorted) % 2 == 0)
		median = (*(int *)sorted->next->next->content +
		*(int *)sorted->next->content) / 2;
	else
		median = *(float *)sorted->next->next->content;
	return (median);
}

int	highest_nbr(t_list *stack)
{
	int max;

	max = 0;
	while(stack)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}
