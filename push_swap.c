#include "push_swap.h"
/*
static	void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	if (stack_a)
	{
		printf("Stack A values:\n");
		while (stack_a)
		{
			printf("%d\n", *(int*)stack_a->content);
			stack_a = stack_a->next;
		}
	}

	if (stack_b)
	{
		printf("Stack B values:\n");
		while (stack_b)
		{
			printf("%d\n", *(int*)stack_b->content);
			stack_b = stack_b->next;
		}
	}
}
*/
static	void	exit_all(t_list **stack_a, t_list **stack_b, bool err)
{
	//print_stacks(*stack_a, *stack_b);
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	if (err)
		printf("Error\n");
	exit (0);
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
    if (argc == 1)
        return (0);
    if (!validate_input(argv, &stack_a))
		exit_all(&stack_a, &stack_b, true);
	if (!stack_sorted(stack_a, ft_lstsize(stack_a)))
		sort_stack(&stack_a, &stack_b, argc - 1);
    exit_all(&stack_a, &stack_b, false);
}
