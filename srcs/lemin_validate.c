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
** Validate a flag.
*/

static int	validate_flags(t_list *rooms, t_list *paths)
{
	int		start;
	int		end;
	t_room	*tmp;

	start = 0;
	end = 0;
	if (rooms != 0 || paths != 0)
	{
		while (rooms)
		{
			tmp = (t_room *)rooms->content;
			if (tmp->flag == STARTROOM)
				start += 1;
			if (tmp->flag == ENDROOM)
				end += 1;
			rooms = rooms->next;
		}
	}
	return (start == 1 && end == 1);
}

/*
** Validate a path.
*/

static int	validate_path(t_room *rooms, t_list *paths)
{
	return ((rooms != 0 && paths != 0) && find(rooms, ENDROOM) >= 0);
}

/*
** Validate the path and the flags.
*/

int			lemin_validate(t_lemin *lemin)
{
	return (validate_path(get_room_flag(STARTROOM, lemin->rooms_list), \
										lemin->paths_list) \
			&& validate_flags(lemin->rooms_list, lemin->paths_list));
}
