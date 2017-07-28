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

void		lemin_start(t_list *rooms, t_list *paths)
{
	t_list	*tmp_r;
	t_list	*tmp_p;
	t_room	*room;
	t_path	*path;

	tmp_r = rooms;
	while (tmp_r)
	{
		room = (t_room *)tmp_r->content;
		tmp_p = paths;
		while (tmp_p)
		{
			path = (t_path *)tmp_p->content;
			if (ft_strequ(path->door1, room->name))
				room->paths = ft_lstpush(room->paths,
						get_room_name(path->door2, rooms));
			if (ft_strequ(path->door2, room->name))
				room->paths = ft_lstpush(room->paths,
						get_room_name(path->door1, rooms));
			tmp_p = tmp_p->next;
		}
		tmp_r = tmp_r->next;
	}
}
