#include "../inc/push_swap.h"

void	free_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	exit_and_free(t_data *data, int n)
{
	if (data->is_av_malloc == 1)
		free_arg(data->av);
}
