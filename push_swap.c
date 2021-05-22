#include "push_swap.h"

static  void    err_exit()
{
    printf("Error\n");
    exit(0);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    if (!is_int(argv))
        err_exit();
	fill_list(argv);
	//sort_stack();
    return (0);
}
