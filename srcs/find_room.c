/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 06:05:22 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 06:05:25 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Find a room, returning the smallest path.
** If none is found, returns an error.
*/

int			find_room(void *room, int targetflag)
{
	t_room	*current;
	t_list	*testing;
	int		smallestpath;
	int		lastpath;

	current = (t_room *)room;
	if (current->flag == targetflag)
		return (0);
	if (current->busy)
		return (-1);
	current->busy = 1;
	smallestpath = FT_INT_MAX;
	testing = current->paths;
	while (testing)
	{
		if ((lastpath = find_room(testing->content, targetflag)) < smallestpath
														&& lastpath != -1)
			smallestpath = 1 + lastpath;
		testing = testing->next;
	}
	current->busy = 0;
	return (smallestpath == FT_INT_MAX ? ERROR : smallestpath);
}
