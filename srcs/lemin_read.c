/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 03:04:05 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 03:04:05 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Read and checks if the line is a command.
*/

static int	read_command(char *line)
{
	int		ret;

	ret = NORMAL;
	if (line[0] != '#')
		ret = IGNORE;
	else if (ft_strequ("##start", line))
		ret = STARTROOM;
	else if (ft_strequ("##end", line))
		ret = ENDROOM;
	return (ret);
}

/*
** Read and checks if the line is a room.
*/

static int	read_room(char *line)
{
	while (*line && *line != ' ')
		line += 1;
	if (*line != ' ')
		return (0);
	line += 1;
	if (*line == '-')
		line += 1;
	while (*line && ft_isdigit(*line))
		line += 1;
	if (*line != ' ')
		return (0);
	line += 1;
	if (*line == '-')
		line += 1;
	while (*line && ft_isdigit(*line))
		line += 1;
	return (*line != '\0' ? 0 : 1);
}

/*
** Read and checks if the line is a path.
*/

static int	read_path(char *line, t_list *rooms)
{
	int		ret;
	t_path	tmp;

	ret = 0;
	if (ft_strchr(line, '-'))
	{
		tmp.door1 = ft_strsub(line, 0, ft_strlchr(line, '-'));
		tmp.door2 = ft_strdup(line + ft_strlchr(line, '-') + 1);
		if (get_room_name(tmp.door1, rooms) && get_room_name(tmp.door2, rooms))
		{
			ret = 1;
			free(tmp.door1);
			free(tmp.door2);
		}
		else
		{
			free(tmp.door1);
			free(tmp.door2);
		}
	}
	return (ret);
}

/*
** Read a line and check if it's a command, path, or a comment.
** When it reads a line that isn't a command, path, or comment,
** breaks from the while loop.
*/

int			lemin_read(t_lemin *lemin)
{
	int		ret;
	char	*line;
	int		flag;
	int		rooms_done;

	flag = NORMAL;
	rooms_done = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (read_command(line))
			flag = (flag == NORMAL) ? read_command(line) : flag;
		else if (read_room(line) && !rooms_done)
		{
			lemin->room_list = ft_lstpush(lemin->room_list, \
											init_room(line, flag));
			flag = NORMAL;
		}
		else if (read_path(line, lemin->room_list) && (rooms_done = 1))
			lemin->path_list = ft_lstpush(lemin->path_list, init_path(line));
		else
			break ;
	}
	ft_memdel((void **)&line);
	return (ret);
}
