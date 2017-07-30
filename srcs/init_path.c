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
** Initialize the path.
*/

t_path		*init_path(char *line)
{
	int		i;
	t_path	*newpath;

	if (!(newpath = (t_path *)malloc(sizeof(t_path))))
		ft_puterror_fd("Memory allocation failed!", MALLC_ERR, FT_STD_ERR);
	i = (int)ft_strlchr(line, '-');
	newpath->door1 = ft_strsub(line, 0, i);
	newpath->door2 = ft_strdup(line + i + 1);
	free(line);
	return (newpath);
}
