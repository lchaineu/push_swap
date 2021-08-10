#include "../inc/push_swap.h"

int	add_elem(t_stack *stack, int new_nb)
{
	t_elem	*new_elem;

	new_elem = (t_elem *)malloc(sizeof(t_elem));
	if (!new_elem)
	{
		free_stack(stack);
		return (0);
	}
	new_elem->nb = new_nb;
	new_elem->next = stack->first;
	if (new_nb > stack->biggest)
		stack->biggest = new_nb;
	if (new_nb > stack->min)
		stack->min = new_nb;
	stack->first = new_elem;
	stack->count++;
	return (1);
}

int	rem_elem(t_stack *stack)
{
	int		temp;
	t_elem	*todelete;

	todelete = stack->first;
	temp = todelete->nb;
	stack->first = todelete->next;
	free(todelete);
	stack->count--;
	return (temp);
}
