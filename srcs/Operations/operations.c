/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:37:21 by lchaineu          #+#    #+#             */
/*   Updated: 2021/09/14 10:37:23 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *stack)
{
	int		temp;

	if (stack->count <= 1)
		return ;
	else
	{
		temp = stack->first->next->nb;
		stack->first->next->nb = stack->first->nb;
		stack->first->nb = temp;
	}	
}

void	rotate(t_stack *stack)
{
	t_elem	*first;
	t_elem	*temp;

	if (stack->count <= 1)
		return ;
	temp = stack->first;
	while (temp->next)
		temp = temp->next;
	first = stack->first;
	stack->first = stack->first->next;
	first->next = NULL;
	temp->next = first;
}

void	rev_rotate(t_stack *stack)
{
	t_elem	*temp;
	t_elem	*last;

	if (stack->count <= 1)
		return ;
	temp = stack->first;
	while (temp->next)
	{
		if (!temp->next->next)
			last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = stack->first;
	stack->first = temp;
}

int	push(t_stack *to_stack, t_stack *from_stack)
{
	if (from_stack->count == 0)
		return (1);
	else if (!add_elem(to_stack, rem_elem(from_stack)))
		return (0);
	return (1);
}
