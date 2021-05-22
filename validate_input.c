#include "push_swap.h"

void	fill_list(char **argv)
{
	int i;
	t_list *new_node;

	i = 1;
	while (argv[i])
	{
		if (is_duplicate(argv[i]))
			return (false);
		ft_lstadd_back(stack_a, )
		i++;
	}

}
bool    is_int(char **argv)
{
    int     i;
    long    num;

    i = 0;
    while (argv[++i])
    {
        if (ft_str_is_numeric(argv[i]))
        {
            num = ft_atoi(argv[i]);
            printf("%ld\n", num);
            if (num < INT_MIN || num > INT_MAX)
                return (false);
        }
        else
            return (false);
    }
    return (true);
}

bool    has_duplicate(char **argv)
{

}
