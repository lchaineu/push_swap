#include "../inc/push_swap.h"

void	ft_lstclear_ps(t_elem *elem)
{
	t_elem	*temp;
	t_elem	*todelete;

	temp = elem;
	while (temp)
	{
		todelete = temp;
		temp = temp->next;
		free(todelete);
	}
	elem = NULL;
}

int	number_of_words(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	stack_biggests_nb(t_stack *stack)
{
	t_elem	*current;

	stack->biggest = -2147483648;
	current = stack->first;
	while (current)
	{
		stack->biggest = (current->nb > stack->biggest)
			? current->nb : stack->biggest;
		current = current->next;
	}
	current = stack->first;
	while (current)
	{
		if (current->nb > stack->biggest_bis && current->nb != stack->biggest)
			stack->biggest_bis = current->nb;
		current = current->next;
	}
	current = stack->first;
	while (current)
	{
		if (current->nb > stack->biggest_ter && current->nb
			!= stack->biggest && current->nb != stack->biggest_bis)
			stack->biggest_ter = current->nb;
		current = current->next;
	}
}
