/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_print_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:37:33 by lchaineu          #+#    #+#             */
/*   Updated: 2021/11/10 15:07:56 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_empty_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	stack->count = 0;
	stack->min = 2147483647;
	stack->biggest = -2147483648;
	return (stack);
}

t_stack	*fill_stack_with_ints(int ac, char **av)
{
	t_stack	*stack;

	stack = init_empty_stack();
	if (stack == NULL)
		return (NULL);
	while (--ac >= 0)
	{
		if (!add_elem(stack, ft_atoi(av[ac])))
			return (NULL);
	}
	return (stack);
}

int	get_proper_stack(int *ac, char ***av, t_data *data)
{
	int	i;

	i = 0;
	if (*ac == 2)
	{
		*av = ft_split((*av)[1], ' ');
		if (*av == NULL)
			return (0);
		*ac = number_of_words(*av);
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
