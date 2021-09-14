/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:37:51 by lchaineu          #+#    #+#             */
/*   Updated: 2021/09/14 10:37:53 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack_of_two(t_stack *a_stack)
{
	if (a_stack->first->nb > a_stack->first->next->nb)
		sa_and_rep(a_stack);
	return ;
}

void	sort_stack_of_three(t_stack *a_stack)
{
	int	nb_one;
	int	nb_two;
	int	nb_three;

	nb_one = a_stack->first->nb;
	nb_two = a_stack->first->next->nb;
	nb_three = a_stack->first->next->next->nb;
	if (nb_one > nb_two && nb_one < nb_three && nb_two < nb_three)
		sa_and_rep(a_stack);
	else if (nb_one < nb_two && nb_one > nb_three && nb_two > nb_three)
		rra_and_rep(a_stack);
	else if (nb_one > nb_two && nb_one > nb_three && nb_two < nb_three)
		ra_and_rep(a_stack);
	else if (nb_one > nb_two && nb_one > nb_three && nb_two > nb_three)
	{
		sa_and_rep(a_stack);
		rra_and_rep(a_stack);
	}
	else if (nb_one < nb_two && nb_one < nb_three && nb_two > nb_three)
	{
		rra_and_rep(a_stack);
		sa_and_rep(a_stack);
	}
}
