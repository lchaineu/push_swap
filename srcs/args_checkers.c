#include "../inc/push_swap.h"

int	is_digits(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	while (j < ac)
	{
		if (!ft_strcmp(av[j], "-") || !ft_strcmp(av[j], "+"))
			return (0);
		i = 0;
		if (av[j][0] == '-' || av[j][0] == '+')
			i++;
		while (av[j][i])
		{
			if (!ft_isdigit(av[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_int_limits(char *str, char sign)
{
	if (sign == 'pos' && ft_strcmp(str, "2147483647") > 0)
		return (0);
	else if (sign == '+' && ft_strcmp(str + 1, "2147483647") > 0)
		return (0);
	else if (sign == '-' && ft_strcmp(str + 1, "2147483647") > 0)
		return (0);
	else
		return (1);
}

int	is_int(char *str)
{
	int		len;
	char	sign;

	sign = 'pos';
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		sign = '-';
		len--;
	}
	if (str[0] == '+')
	{
		sign = '+';
		len--;
	}
	if (len > 10)
		return (0);
	if (len < 10)
		return (1);
	else
		return (check_int_limits(str, sign));
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 0;
	if (!is_digits(ac, av))
		return (0);
	while (i < ac)
	{
		if (!is_int(av[i]))
			return (0);
		i++;
	}
	return (1);
}
