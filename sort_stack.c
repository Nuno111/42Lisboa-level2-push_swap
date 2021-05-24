#include "push_swap.h"

bool	stack_sorted(t_list *stack_a)
{
	while(stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void    sort_stack(t_list **stack_a, t_list **stack_b, int argc)
{

}
