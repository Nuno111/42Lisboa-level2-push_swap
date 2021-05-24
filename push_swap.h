#include <stdio.h>
#include "libft.h"
#include <limits.h>

bool    validate_input(char **argv, t_list **stack_a);
void    swap_stack(t_list **stack, char *msg);
void	push_stack(t_list **stack_rem, t_list **stack_add, char *msg);
void	rotate_stack(t_list **stack, char *msg);
void	rrotate_stack(t_list **stack, char *msg);
void	swap_stacks(t_list **stack_a, t_list **stack_b);
void	rrotate_stacks(t_list **stack_a, t_list **stack_b);
void	rotate_stacks(t_list **stack_a, t_list **stack_b);
bool	stack_sorted(t_list *stack_a);
