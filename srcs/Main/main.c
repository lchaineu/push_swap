#include "../inc/push_swap.h"

void	sort_by_type_of_stack(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->count == 1)
		return ;
	else if (a_stack->count == 2)
		sort_stack_of_two(a_stack);
	else if (a_stack->count == 3)
		sort_stack_of_three(a_stack);
	else
	{
		stack_biggests_nb(a_stack);
		sort_big_stack(a_stack, b_stack);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	t_data	data;

	if (!get_proper_stack(&ac, &av, &data))
		exit_and_free(&data, 0);
	if (ac == 0)
		return (EXIT_SUCCESS);
	if (!check_arg(ac, av))
		exit_and_free(&data, 0);	
	a_stack = fill_stack_with_ints(ac, av);
	if (a_stack == NULL)
		exit_and_free(&data, 0);
	data.a_stack = a_stack;
	b_stack = init_empty_stack();
	if (b_stack == NULL)
		exit_and_free(&data, 1);	
	data.b_stack = b_stack;
	if (!is_double(a_stack))
		exit_and_free(&data, 2);
	if (is_sorted(a_stack, b_stack))
		exit_and_free(&data, 3);
	sort_by_type_of_stack(a_stack, b_stack);
	exit_and_free(&data, 3);
}
