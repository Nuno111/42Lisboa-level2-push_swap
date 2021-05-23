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

void	push_stack(t_list **stack_rem, t_list **stack_add, char *msg)
{
	t_list *new_node;
	t_list *node_to_free;

	if (!(*stack_rem))
		return ;
	new_node = ft_lstnew(*(int *)(*stack_rem)->content);
	ft_lstadd_front(stack_add, new_node);
	node_to_free = *stack_rem;
	stack_rem = &(node_to_free)->next;
	free(node_to_free);
	if (msg)
		printf("%s\n", msg);
}

void	rotate_stack(t_list **stack, char *msg)
{
	t_list *node_to_rotate;

	node_to_rotate = *stack;
	node_to_rotate->next = NULL;
	stack = &(*stack)->next;
	ft_lstadd_back(stack, node_to_rotate);
	if (msg)
		printf("%s\n",msg);
}


void	rrotate_stack(t_list **stack, char *msg)
{
	t_list	*node_to_rotate;
	t_list	*new_last_node;

	node_to_rotate = ft_lstlast(*stack);
	ft_lstadd_front(stack, node_to_rotate);
	new_last_node = ft_lstlast;
	new_last_node->next = NULL;
	if (msg)
		printf("%s\n",msg);
}
