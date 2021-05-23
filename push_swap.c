#include "push_swap.h"

static  void    err_exit(t_list **stack_a)
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
		err_exit(&stack_a);
	if (stack_a)
		ft_lstclear(&stack_a, free);
	//sort_stack(stack_a);
    return (0);
}
