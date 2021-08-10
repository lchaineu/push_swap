#include "../inc/push_swap.h"

void	swap(t_stack *stack)
{
	int		temp;

	if (stack->count <= 1)
		return ;
	else
	{
		temp = stack->first;
		stack->first = stack->first->next;
		stack->first->next = temp;
	}	
}

void	rotate(t_stack *stack)
{
	t_elem	*first;
	t_elem	*temp;

	if (stack->count <= 1)
		return ;
	temp = stack->first;
	while (temp->next)
		temp = temp->next;
	first = stack->first;
	stack->first = stack->first->next;
	first->next = NULL;
	temp->next = first;
}

void	rev_rotate(t_stack *stack)
{
	t_elem	*temp;
	t_elem	*last;

	if (stack->count <= 1)
		return ;
	temp = stack->first;
	while (temp->next)
	{
		if (!temp->next->next)
			last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = stack->first;
	stack->first = temp;
}

int	push(t_stack *a_stack, t_stack *b_stack)
{
	if (b_stack->count == 0)
		return (1);
	else if (!add_elem(a_stack, rem_elem(b_stack)))
		return (0);
	return (1);
}
