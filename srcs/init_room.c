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
** Initialize the room.
** ...
** ...
** ...
** Maybe compare with whitespaces ('\n' && ' '), check the pdf to see if
** it's allowed.
*/

t_room		*init_room(char *line, int room_flag)
{
	int		i;
	t_room	*newroom;

	i = 0;
	if (!(newroom = malloc(sizeof(t_room))))
		ft_puterror_fd("Memory allocation failed!", ERROR, FT_STD_ERR);
	while (line[i] != ' ')
		i += 1;
	newroom->flag = room_flag;
	newroom->name = ft_strsub(line, 0, i);
	while (line[i] == ' ')
		i += 1;
	newroom->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i += 1;
	while (line[i] == ' ')
		i += 1;
	newroom->y = ft_atoi(line + i);
	newroom->paths = NULL;
	newroom->busy = 0;
	newroom->has_ant = 0;
	free(line);
	return (newroom);
}
