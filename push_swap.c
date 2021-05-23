#include "push_swap.h"

static	int	exit_succ(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstclear(&stack_a, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
	return (0);
}

static  void    exit_err(t_list **stack_a)
{
	ft_lstclear(stack_a, free);
    printf("Error\n");
    exit(0);
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
		exit_err(&stack_a);
	//sort_stack(stack_a);
    return (exit_succ(stack_a, stack_b));
}
