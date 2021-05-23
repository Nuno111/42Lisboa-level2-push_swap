#include "push_swap.h"

void    swap_stack(t_list **stack, char *msg)
{
    int tmp;

    tmp = *(int *)(*stack)->content;
    *(int *)(*stack)->content = *(int *)(*stack)->next->content;
    *(int *)(*stack)->next->content = tmp;
	if (msg)
		printf("%s\n", msg);
}

void	swap_stacks(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a, NULL);
	swap_stack(stack_b, NULL);
	printf("ss\n");
}

void	push_stack(t_list **stack_rem, t_list **stack_add, char *msg)
{
	t_list *new_node;
	t_list *node_to_free;

	new_node = ft_lstnew(*(int *)(*stack_rem)->content);
	ft_lstadd_front(stack_add, new_node);
	node_to_free = *stack_rem;
	stack_rem = &(node_to_free)->next;
	free(node_to_free);
	if (msg)
		printf("%s\n", msg);
}
