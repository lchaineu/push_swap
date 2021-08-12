#include "../inc/push_swap.h"

static int	is_digits(char *str)
{
	int	i;

	i = 0;
	if (!ft_strcmp(str, "-") || !ft_strcmp(str, "+"))
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_int_limits(char *str, char sign)
{
	if (sign == 'p' && ft_strcmp(str, "2147483647") > 0)
		return (0);
	else if (sign == '+' && ft_strcmp(str + 1, "2147483647") > 0)
		return (0);
	else if (sign == '-' && ft_strcmp(str + 1, "2147483647") > 0)
		return (0);
	else
		return (1);
}

static int	is_int(char *str)
{
	int		len;
	char	sign;

	sign = 'p';
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
	while (i < ac)
	{
		if (!is_digits(av[1]))
			return (0);
		if (!is_int(av[i]))
			return (0);
		i++;
	}
	return (1);
}
