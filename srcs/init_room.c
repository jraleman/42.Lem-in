/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:50:47 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 01:50:48 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ...
*/

t_room	*init_room(char *line, int room_flag)
{
	t_room		*newroom;
	int			i;

	i = 0;
	newroom = malloc(sizeof(t_room));
	if (!newroom)
		return (NULL);
	while (line[i] != ' ')
		i++;
	newroom->flag = room_flag;
	newroom->name = ft_strsub(line, 0, i);
	while (line[i] == ' ')
		i++;
	newroom->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	newroom->y = ft_atoi(line + i);
	newroom->paths = NULL;
	newroom->busy = 0;
	newroom->has_ant = 0;
	free(line);
	return (newroom);
}
