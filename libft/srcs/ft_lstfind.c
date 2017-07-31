/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 04:00:07 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/23 04:00:28 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstfind(t_list *begin_list, void *data, int (*cmp)())
{
	t_list *node;

	node = begin_list;
	while (node)
	{
		if ((cmp)(node->content, data) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
