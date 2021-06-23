#include "push_swap.h"

void	swap_stack(t_list **stack, char *msg)
{
	int	tmp;

	tmp = *(int *)(*stack)->content;
	*(int *)(*stack)->content = *(int *)(*stack)->next->content;
	*(int *)(*stack)->next->content = tmp;
	if (msg)
		ft_putstr(msg);
}

void	push_stack(t_list **stack_rem, t_list **stack_add, char *msg)
{
	t_list	*tmp;

	if (!(*stack_rem || !stack_add))
		return ;
	tmp = *stack_rem;
	*stack_rem = (*stack_rem)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_add, tmp);
	if (msg)
		ft_putstr(msg);
}

void	rotate_stack(t_list **stack, char *msg)
{
	t_list	*node_to_rotate;

	node_to_rotate = *stack;
	*stack = (*stack)->next;
	node_to_rotate->next = NULL;
	ft_lstadd_back(stack, node_to_rotate);
	if (msg)
		ft_putstr(msg);
}

void	rrotate_stack(t_list **stack, char *msg)
{
	t_list	*node_to_rotate;
	t_list	*new_last_node;

	new_last_node = *stack;
	while (new_last_node->next->next)
		new_last_node = new_last_node->next;
	node_to_rotate = ft_lstlast(*stack);
	ft_lstadd_front(stack, node_to_rotate);
	new_last_node->next = NULL;
	if (msg)
		ft_putstr(msg);
}
