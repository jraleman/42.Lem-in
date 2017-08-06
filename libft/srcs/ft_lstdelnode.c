/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:15:38 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/23 03:50:55 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnode(t_list **head, t_list *node, void (*del)(void*, size_t))
{
	t_list *temp;

	if (!node)
		return ;
	if (*head == node)
		*head = (*head)->next;
	else
	{
		temp = *head;
		while (temp->next != 0 && temp->next != node)
			temp = temp->next;
		if (temp->next == 0)
			return ;
		temp->next = temp->next->next;
	}
	ft_lstdelone(&node, del);
	free(node);
	node = NULL;
}
