/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 05:05:24 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/27 05:05:25 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ...
*/

static void	delete_room(void *data)
{
	t_room		*room;

	room = (t_room *)data;
	ft_strdel(&room->name);
	ft_lst_rec_free(room->paths);
	free(data);
	data = NULL;
}

/*
** ...
*/

static void	delete_path(void *data)
{
	t_path		*path;

	path = (t_path *)data;
	ft_strdel(&path->door1);
	ft_strdel(&path->door2);
	free(data);
	data = NULL;
}

/*
** ...
*/

void	lemin_end(t_list *rooms, t_list *paths)
{
	if (rooms)
	{
		ft_lstforeach(rooms, delete_room);
		ft_lst_rec_free(rooms);
	}
	if (paths)
	{
		ft_lstforeach(paths, delete_path);
		ft_lst_rec_free(paths);
	}
}
