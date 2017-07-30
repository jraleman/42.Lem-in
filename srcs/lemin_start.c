/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_star.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 04:48:11 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 04:48:12 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Start going from room to room.
*/

void		lemin_start(t_lemin *lemin)
{
	t_room	*room;
	t_path	*path;
	t_list	*tmp_room;
	t_list	*tmp_path;

	tmp_room = lemin->room_list;
	while (tmp_room != 0)
	{
		room = (t_room *)tmp_room->content;
		tmp_path = lemin->path_list;
		while (tmp_path != 0)
		{
			path = (t_path *)tmp_path->content;
			if (ft_strequ(path->door1, room->name))
				room->paths = ft_lstpush(room->paths,
						get_room_name(path->door2, lemin->room_list));
			if (ft_strequ(path->door2, room->name))
				room->paths = ft_lstpush(room->paths,
						get_room_name(path->door1, lemin->room_list));
			tmp_path = tmp_path->next;
		}
		tmp_room = tmp_room->next;
	}
	return ;
}
