#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include <limits.h>

void	save_chunks_size(int **chunks, int size);
int		par_or_impar(int size);
bool	validate_input(char **argv, t_list **stack_a);
void	swap_stack(t_list **stack, char *msg);
void	push_stack(t_list **stack_rem, t_list **stack_add, char *msg);
void	rotate_stack(t_list **stack, char *msg);
void	rrotate_stack(t_list **stack, char *msg);
void	swap_stacks(t_list **stack_a, t_list **stack_b);
void	rrotate_stacks(t_list **stack_a, t_list **stack_b);
void	rotate_stacks(t_list **stack_a, t_list **stack_b);
bool	stack_sorted(t_list *stack, int size);
void	solve_small(t_list **stack);
void	solve_medium(t_list **stack_a, t_list **stack_b);
void	solve_large(t_list **stack_a, t_list **stack_b, int size);
void	sort_stack(t_list **stack_a, t_list **stack_b, int argc);
float	get_median(t_list *stack, int size);
int		get_highest(t_list *stack);
int		get_smallest(t_list *stack);
void	split_a(t_list **stack_a, t_list **stack_b, int **chunks, int size);
void	handle_chunks(t_list **stack_a, t_list **stack_b, int size);
void	push_to_a(t_list **stack_b, t_list **stack_a, int size);

#endif