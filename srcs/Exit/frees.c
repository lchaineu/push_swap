/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:36:56 by lchaineu          #+#    #+#             */
/*   Updated: 2021/09/14 10:36:58 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_stack(t_stack	*stack)
{
	ft_lstclear_ps(stack->first);
	free(stack);
}

static void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_and_free(t_data *data, int n)
{
	if (data->is_av_malloc == 1)
		free_arg(data->av);
	if (n >= 1)
		free_stack(data->a_stack);
	if (n >= 2)
		free_stack(data->b_stack);
	if (n <= 2)
		error();
	if (n > 2)
		exit(EXIT_SUCCESS);
}
