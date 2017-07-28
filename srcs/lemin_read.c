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

	if (*line != '#')
		ret = 0;
	else if (ft_strequ("##start", line))
		ret = STARTROOM;
	else if (ft_strequ("##end", line))
		ret = ENDROOM;
	else
		ret = NORMAL;
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
	if (*line != '\0')
		return (0);
	return (1);
}

/*
** Read and checks if the line is a path.
*/

static int	read_path(char *line, t_list *rooms)
{
	t_path	tmp;

	if (ft_strchr(line, '-'))
	{
		tmp.door1 = ft_strsub(line, 0, ft_strlchr(line, '-'));
		tmp.door2 = ft_strdup(line + ft_strlchr(line, '-') + 1);
		if ((get_room_name(tmp.door1, rooms)
			&& get_room_name(tmp.door2, rooms)))
		{
			free(tmp.door1);
			free(tmp.door2);
			return (1);
		}
		else
		{
			free(tmp.door1);
			free(tmp.door2);
			return (0);
		}
	}
	else
		return (0);
}

/*
** Read a line and check if it's a command, path, or a comment.
*/

int			lemin_read(t_list **rooms, t_list **paths)
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
			*rooms = ft_lstpush(*rooms, init_room(line, flag));
			flag = NORMAL;
		}
		else if (read_path(line, *rooms) && (rooms_done = 1))
			*paths = ft_lstpush(*paths, init_path(line));
		else
			break ;
	}
	free(line);
	return (ret);
}
