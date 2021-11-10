/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:37:37 by lchaineu          #+#    #+#             */
/*   Updated: 2021/11/10 13:43:19 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_double(t_stack *stack)
{
	t_elem	*base;
	t_elem	*current;

	base = stack->first;
	while (base)
	{
		current = base->next;
		while (current)
		{
			if (current->nb == base->nb)
				return (0);
			current = current->next;
		}
		base = base->next;
	}
	return (1);
}

int	is_sorted(t_stack *a_stack)
{
	t_elem	*current;

	current = a_stack->first;
	while (current->next)
	{
		if (current->nb > current->next->nb)
			return (0);
		current = current->next;
	}
	return (1);
}
