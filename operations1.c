#include "push_swap.h"

void	swap_stacks(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a, NULL);
	swap_stack(stack_b, NULL);
	ft_putstr("ss\n");
}

void	rotate_stacks(t_list **stack_a, t_list **stack_b)
{
	rotate_stack(stack_a, NULL);
	rotate_stack(stack_b, NULL);
	ft_putstr("rr\n");
}

void	rrotate_stacks(t_list **stack_a, t_list **stack_b)
{
	rrotate_stack(stack_a, NULL);
	rrotate_stack(stack_b, NULL);
	ft_putstr("rrr\n");
}
