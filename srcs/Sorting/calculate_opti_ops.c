#include "../inc/push_swap.h"

static int	ra_amount(t_elem *elem, t_stack *stack)
{
	int		answer;
	t_elem	*temp;

	answer = 0;
	temp = stack->first;
	while (temp != elem)
	{
		temp = temp->next;
		answer++;
	}
	return (answer);
}

static int	rb_amount_bis(t_elem *elem, t_elem *elem_temp)
{
	int	nb_temp;
	int	answer;
	int	answer_temp;

	nb_temp = -2147483648;
	answer = 0;
	answer_temp = 0;
	while (elem_temp)
	{
		if (elem_temp->nb < elem->nb
			&& elem_temp->nb > nb_temp)
		{
			nb_temp = elem_temp->nb;
			answer = answer_temp;
		}
		answer_temp++;
		elem_temp = elem_temp->next;
	}
	return (answer);
}

static int	rb_amount(t_elem *elem, t_stack *stack)
{
	t_elem	*elem_temp;
	int		answer;

	answer = 0;
	if (stack->count < 1)
		return (0);
	elem_temp = stack->first;
	if (elem->nb < stack->min)
	{
		while (elem_temp->nb != stack->biggest)
		{
			answer++;
			elem_temp = elem_temp->next;
		}
	}
	else
		answer = rb_amount_bis(elem, elem_temp);
	return (answer);
}

static void	calculate_op_amount_and_type(t_sorting *sort)
{
	int	rarrb;
	int	rr;
	int	rrr;

	rarrb = find_min(sort->ra, sort->rra) + find_min(sort->rb, sort->rrb);
	rr = find_max(sort->ra, sort->rb);
	rrr = find_max(sort->rra, sort->rrb);
	sort->op_amount = find_min(rarrb, rrr);
	sort->op_amount = find_min(sort->op_amount, rr);
	if (sort->op_amount == rarrb)
		sort->op_combi_type = '0';
	else if (sort->op_amount == rr)
		sort->op_combi_type = '1';
	else
		sort->op_combi_type = '2';
}

t_sorting	opti_ops(t_elem *elem, t_stack *a_stack, t_stack *b_stack)
{
	t_sorting	tot_ops;

	tot_ops.ra = ra_amount(elem, a_stack);
	tot_ops.rra = (a_stack->count - tot_ops.ra) % a_stack->count;
	tot_ops.rb = rb_amount(elem, b_stack);
	if (b_stack->count == 0)
		tot_ops.rrb = 0;
	else
		tot_ops.rrb = ((b_stack->count - tot_ops.rb) % tot_ops.rrb);
	calculate_op_amount_and_type(&tot_ops);
	return (tot_ops);
}
