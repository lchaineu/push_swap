/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:11:20 by lchaineu          #+#    #+#             */
/*   Updated: 2021/08/10 10:28:08 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*act;

	temp = *lst;
	while (temp)
	{
		act = temp;
		del(temp->content);
		temp = temp->next;
		free(act);
	}
	*lst = NULL;
}
