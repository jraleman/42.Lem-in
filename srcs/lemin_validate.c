/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 05:01:41 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/27 05:01:42 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ...
*/

static int	unique_flags(t_list *rooms, t_list *paths)
{
	int		starts_found;
	int		ends_found;
	t_room	*tmp;

	starts_found = 0;
	ends_found = 0;
	if (!rooms || !paths)
		return (0);
	while (rooms)
	{
		tmp = (t_room *)rooms->content;
		if (tmp->flag == STARTROOM)
			starts_found++;
		if (tmp->flag == ENDROOM)
			ends_found++;
		rooms = rooms->next;
	}
	if (starts_found != 1)
		return (0);
	if (ends_found != 1)
		return (0);
	return (1);
}

/*
** ...
*/

static int	path_exists(t_room *rooms, t_list *paths)
{
	int		debug;

	if (!rooms || !paths)
		return (0);
	debug = find(rooms, ENDROOM);
	if (debug < 0 || debug == 2147483647)
		return (0);
	return (1);
}

/*
** ...
*/

int 		lemin_validate(t_list *rooms, t_list *paths)
{
	return (path_exists(get_room_by_flag(STARTROOM, rooms), paths) \
			&& unique_flags(rooms, paths));
}
