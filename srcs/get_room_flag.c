/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 00:55:41 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 00:55:42 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Get the room by its flag.
*/

t_room		*get_room_flag(int flag, t_list *list)
{
	int		done;
	t_room	*tmp;

	done = 0;
	while (list && !done)
	{
		tmp = (t_room *)list->content;
		done = tmp->flag == flag ? 1 : 0;
		list = list->next;
	}
	return (done ? tmp : NULL);
}
