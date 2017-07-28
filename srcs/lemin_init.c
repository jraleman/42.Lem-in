/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 00:17:20 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 00:17:21 by jaleman          ###   ########.fr       */
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

/*
** ...
*/

t_path	*init_path(char *line)
{
	t_path		*newpath;
	int			score_pos;

	newpath = malloc(sizeof(t_path));
	if (!newpath)
		return (NULL);
	score_pos = (int)ft_strlchr(line, '-');
	newpath->door1 = ft_strsub(line, 0, score_pos);
	newpath->door2 = ft_strdup(line + score_pos + 1);
	free(line);
	return (newpath);
}



////////////////////////////////////////////////////////////////////////////////

/*
** ...
*/

static t_ant	*init_ants(int total_ants, t_list *rooms)
{
	int			i;
	t_ant		*ants;

	i = 0;
	if (!(ants = malloc(sizeof(t_ant) * total_ants)))
		ft_puterror_fd("Memory allocation failed!", ERROR, FT_STD_ERR);
	while (i < total_ants)
	{
		ants[i].room = get_room_by_flag(STARTROOM, rooms);
		ants[i].did_turn = 0;
		ants[i].id = i + 1;
		i += 1;
	}
	return (ants);
}

/*
** ...
*/

t_lemin			*lemin_init(void)
{
	t_lemin 	*init;

	if (!(init = (t_lemin *)malloc(sizeof(t_lemin))))
		ft_puterror_fd("Memory allocation failed!", ERROR, FT_STD_ERR);
	init->rooms_list = NULL;
	init->paths_list = NULL;
	if ((init->ants_total = get_ants_total()) == FALSE)
	{
		lemin_end(init);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}
	if (lemin_read(&init->rooms_list, &init->paths_list) == ERROR)
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	if (!init->rooms_list || !init->paths_list)
	{
		lemin_end(init);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}
	init->ants_list = init_ants(init->ants_total, init->rooms_list);
	return (init);
}
