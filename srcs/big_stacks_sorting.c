#include "../inc/push_swap.h"

t_sorting	which_to_insert(t_stack *a_stack, t_stack *b_stack)
{
	
}

void	sort_big_stack(t_stack *a_stack, t_stack *b_stack)
{
	t_sorting	to_insert;
	int			nb;

	while (a_stack->count > 3)
	{
		to_insert = which_to_insert(a_stack, b_stack);

	}
}