#include "../inc/push_swap.h"

t_stack	*init_empty_stack(void)
{
	t_stack	*stack;

	if (!(stack = (t_stack*) malloc(sizeof(t_stack))))
		return (NULL);
	stack->first = NULL;
	stack->count = 0;
	stack->min = 2147483647;
	stack->max = -2147483648;
	return (stack);
}

t_stack	*fill_stack_with_ints(int ac, char **av)
{
	int		i;
	int		nb;
	t_stack	*stack;

	i = ac;
	stack = init_empty_stack();
	if (stack = NULL)
		return (NULL);
	while (i >= 0)
	{
		nb = ft_atoi(av[i]);
		if (!add_elem(stack, nb))
		{
			free_stack(stack);
			return (NULL);
		}
		i--;
	}
	return (stack);
}
