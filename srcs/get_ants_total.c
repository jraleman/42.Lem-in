/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_total.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 03:46:19 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/27 03:46:20 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Get the total number of ants.
*/

int			get_ants_total(void)
{
	char	*line;
	int		ant_number;

	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		while (*line == '#')
		{
			free(line);
			if (get_next_line(0, &line) == ERROR)
			{
				line = NULL;
				break ;
			}
		}
	}
	ant_number = (line != NULL && *line != '\0') ? atoi(line) : 0;
	ft_memdel((void **)&line);
	return (ant_number);
}
