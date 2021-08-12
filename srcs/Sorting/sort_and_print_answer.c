#include "../inc/push_swap.h"

static void	apply_rr(t_sorting sort, t_stack *a_stack, t_stack *b_stack)
{
	int	i;

	i = 0;
	while (i < find_min(sort.ra, sort.rb))
	{
		rotate(a_stack);
		rotate(b_stack);
		write(1, "rr\n", 3);
		i++;
	}
	if (sort.ra > sort.rb)
		while (i++ < sort.ra)
			ra_and_rep(a_stack);
	else
	{
		while (i++ < sort.rb)
			rb_and_rep(b_stack);
	}
}

static void	apply_rrr(t_sorting sort, t_stack *a_stack, t_stack *b_stack)
{
	int	i;

	i = 0;
	while (i < find_min(sort.rra, sort.rrb))
	{
		rev_rotate(a_stack);
		rev_rotate(b_stack);
		write(1, "rrr\n", 4);
		i++;
	}
	if (sort.rra > sort.rrb)
		while (i++ < sort.rra)
			rra_and_rep(a_stack);
	else
	{
		while (i++ < sort.rrb)
			rrb_and_rep(b_stack);
	}
}

static void	apply_minimum(t_sorting sort, t_stack *a_stack, t_stack *b_stack)
{
	int	i;

	i = -1;
	if (sort.ra < sort.rra)
		while (++i < sort.ra)
			ra_and_rep(a_stack);
	else
		while (++i < sort.rra)
			rra_and_rep(a_stack);
	i = -1;
	if (sort.rb < sort.rrb)
		while (++i < sort.rb)
			rb_and_rep(b_stack);
	else
		while (++i < sort.rrb)
			rrb_and_rep(b_stack);
}

void	do_sort_and_print(t_sorting sort, t_stack *a_stack, t_stack *b_stack)
{
	if (sort.op_combi_type == '1')
		apply_rr(sort, a_stack, b_stack);
	else if (sort.op_combi_type == '2')
		apply_rrr(sort, a_stack, b_stack);
	else
		apply_minimum(sort, a_stack, b_stack);
}
