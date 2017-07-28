/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:57:42 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 05:57:46 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lemin.h"




int			find(void *room, int targetflag)
{
	t_room		*current;
	t_list		*testing;
	int			smallestpath;
	int			lastpath;

	current = (t_room *)room;
	if (current->flag == targetflag)
		return (0);
	if (current->busy)
		return (-1);
	current->busy = 1;
	smallestpath = 2147483647;
	testing = current->paths;
	while (testing)
	{
		if ((lastpath = find(testing->content, targetflag)) < smallestpath
														&& lastpath != -1)
			smallestpath = 1 + lastpath;
		testing = testing->next;
	}
	current->busy = 0;
	if (smallestpath == 2147483647)
		return (-1);
	else
		return (smallestpath);
}






void	move(t_ant *ant, t_room *room)
{
	ant->room->has_ant = 0;
	ant->last = ant->room;
	ant->room = room;
	ant->room->has_ant = 1;
	printf("L%d-%s ", ant->id, ant->room->name);
}

void	play(t_ant *ant)
{
	t_list		*ls;
	t_room		*tmp;
	t_room		*next;
	int			distance;
	int			result;

	distance = 2147483647;
	ls = ant->room->paths;
	while (ls)
	{
		tmp = (t_room *)ls->content;
		if ((tmp->flag == ENDROOM || !tmp->has_ant) && tmp != ant->last)
		{
			result = find(tmp, ENDROOM);
			if (result < distance && result > -1)
			{
				distance = result;
				next = tmp;
			}
		}
		ls = ls->next;
	}
	if (distance < 2147483647)
		move(ant, next);
}
