#include "../inc/push_swap.h"

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
	if (!(a_stack = fill_stack(ac,av)))
		exit_and_free(&data, 0);
	data.a_stack = a_stack;
	if (!(b_stack = init_empty_stack()))
		exit_and_free(&data, 1);
	data.b_stack = b_stack;
}
