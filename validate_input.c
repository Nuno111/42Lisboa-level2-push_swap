#include "push_swap.h"

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