#include "../inc/push_swap.h"

void	sa_and_rep(t_stack *a_stack)
{
	swap(a_stack);
	write(1, "sa\n", 3);
}

void	ra_and_rep(t_stack *a_stack)
{
	rotate(a_stack);
	write(1, "ra\n", 3);
}

void	rra_and_rep(t_stack *a_stack)
{
	rev_rotate(a_stack);
	write(1, "rra\n", 4);
}

void	rb_and_rep(t_stack *b_stack)
{
	rotate(b_stack);
	write(1, "rb\n", 3);
}

void	rrb_and_rep(t_stack *b_stack)
{
	rev_rotate(b_stack);
	write(1, "rrb\n", 4);
}
