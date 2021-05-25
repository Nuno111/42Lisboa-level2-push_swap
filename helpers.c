#include "push_swap.h"

int		highest_nbr(t_list *stack)
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
