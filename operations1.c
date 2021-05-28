#include "push_swap.h"


void	swap_stacks(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a, NULL);
	swap_stack(stack_b, NULL);
	printf("ss\n");
}

void	rotate_stacks(t_list **stack_a, t_list **stack_b)
{
	rotate_stack(stack_a, NULL);
	rotate_stack(stack_b, NULL);
	printf("rr\n");
}

void	rrotate_stacks(t_list **stack_a, t_list **stack_b)
{
	rrotate_stack(stack_a, NULL);
	rrotate_stack(stack_b, NULL);
	printf("rrr\n");
}
