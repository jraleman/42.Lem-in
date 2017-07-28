/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:50:25 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 01:50:26 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
