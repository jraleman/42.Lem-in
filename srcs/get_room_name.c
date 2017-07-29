/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 00:55:47 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 00:55:48 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Get the room by its name.
*/

t_room		*get_room_name(char *name, t_list *list)
{
	int		done;
	t_room	*tmp;

	done = 0;
	while (list && !done)
	{
		tmp = (t_room *)list->content;
		done = ft_strequ(name, tmp->name);
		list = list->next;
	}
	return (done ? tmp : NULL);
}
