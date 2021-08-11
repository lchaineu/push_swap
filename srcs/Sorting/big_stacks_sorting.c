#include "../inc/push_swap.h"

int	amount_rotation_needed_bstack(t_stack *stack)
{
	t_elem	*temp;
	int		answer;

	temp = stack->first;
	answer = 0;
	while (temp->nb != stack->biggest)
	{
		temp = temp->next;
		answer++;
	}
	return (answer);
}

static t_sorting	which_ops_for_quickest(t_stack *a_stack, t_stack *b_stack)
{
	t_elem		*current;
	t_sorting	quickests_ops;
	t_sorting	temp;

	current = a_stack->first;
	while (current->nb == a_stack->biggest || current->nb
		== a_stack->biggest_bis || current->nb == a_stack->biggest_ter)
		current = current->next;
	quickests_ops = opti_ops(current, a_stack, b_stack);
	current = current->next;
	while (current)
	{
		temp = opti_ops(current, a_stack, b_stack);
		if (temp.op_amount < quickests_ops.op_amount
			&& current->nb != a_stack->biggest
			&& current->nb != a_stack->biggest_bis && current->nb
			!= a_stack->biggest_ter)
			quickests_ops = temp;
		current = current->next;
	}
	return (quickests_ops);
}

void	sort_big_stack(t_stack *a_stack, t_stack *b_stack)
{
	t_sorting	ops_to_apply;
	int			rb_qty;

	while (a_stack->count > 3)
	{
		ops_to_apply = which_ops_for_quickest(a_stack, b_stack);
		do_sort_and_print(ops_to_apply, a_stack, b_stack);
		if (!push(a_stack, b_stack))
			return ;
		write(1, "pb\n", 3);
	}
	rb_qty = amount_rotation_needed_bstack(b_stack);
	if (rb_qty < (b_stack->count - rb_qty) % b_stack->count)
		while (b_stack->first->nb != b_stack->biggest)
			rb_and_rep(b_stack);
	else
		while (b_stack->first->nb != b_stack->biggest)
			rrb_and_rep(b_stack);
	sort_stack_of_three(a_stack);
	while (b_stack->first)
	{
		if (!push(a_stack, b_stack))
			return ;
		write(1, "pa\n", 3);
	}
}
