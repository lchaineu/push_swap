#include "../inc/push_swap.h"

int	is_double(t_stack *stack)
{
	t_elem	*base;
	t_elem	*current;

	base = stack->first;
	while (base)
	{
		current = base->next;
		while (current)
		{
			if (current->nb == base->nb)
				return (0);
			current = current->next;
		}
		base = base->next;
	}
	return (1);
}

int	is_sorted(t_stack *a_stack, t_stack *b_stack)
{
	t_elem	*current;

	if (!a_stack->first)
		return (0);
	current = a_stack->first;
	while (current->next)
	{
		if (current->nb > current->next->nb)
			return (0);
		current = current->next;
	}
	if (b_stack->first != NULL)
		return (0);
	return (1);
}
