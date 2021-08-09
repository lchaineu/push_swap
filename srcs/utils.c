#include "../inc/push_swap.h"

int	number_of_words(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	get_proper_stack(int *ac, char ***av, t_data *data)
{
	int	i;

	i = 0;
	if (*ac == 2)
	{
		if (!(*av = ft_split((*av)[1], ' ')))
			return (0);
		*ac = nb_of_words(*av);
		data->is_av_malloc = 1;
		data->av = *av;
	}
	else
	{
		while (i < *ac - 1)
		{
			(*av)[i] = (*av)[i + 1];
			i++;
		}
		(*av)[i] = 0;
		(*ac)--;
	}
	return (1);
}
