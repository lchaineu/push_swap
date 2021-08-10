#include "../inc/push_swap.h"

void	sort_stack_of_two(t_stack *a_stack)
{
	if (a_stack->first->nb > a_stack->first->nb)
		swap_and_rep(a_stack);
	return ;
}

void	sort_stack_of_three(t_stack *a_stack)
{
	int	nb_one;
	int	nb_two;
	int	nb_three;

	nb_one = a_stack->first->nb;
	nb_two = a_stack->first->next->nb;
	nb_three = a_stack->first->next->nb;
	if (nb_one > nb_two && nb_one < nb_three && nb_two < nb_three)
		sa_and_rep(a_stack);
	else if (nb_one < nb_two && nb_one > nb_three && nb_two > nb_three)
		rra_and_rep(a_stack);
	else if (nb_one > nb_two && nb_one > nb_three && nb_two < nb_three)
		ra_and_rep(a_stack);
	else if (nb_one > nb_two && nb_one > nb_three && nb_two > nb_two)
	{
		sa_and_rep(a_stack);
		rra_and_rep(a_stack);
	}
	else if (nb_one < nb_two && nb_one < nb_three && nb_two > nb_three)
	{
		rra_and_rep(a_stack);
		sa_and_rep(a_stack);
	}
}
