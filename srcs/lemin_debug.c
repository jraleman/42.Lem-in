/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 17:56:41 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/29 17:56:44 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** 2D String array to store the ascii art of the ants.
*/

char const	g_ant[ANT_NUM][ANT_HEIGHT][ANT_WIDTH] =
{
	{
		{"    \\_/   \n"},
		{"   '-0-'   \n"},
		{"   --0--   \n"},
		{"   .-0-.   \n"},
	},
	{
		{"      \\_/ \n"},
		{"    '-0-'  \n"},
		{"   --0--   \n"},
		{"   .-0-.   \n"},
	},
	{
		{"  \\_/     \n"},
		{"  '-0-'    \n"},
		{"   --0--   \n"},
		{"   .-0-.   \n"},
	}
};

/*
** Display the debug information to the standard out.
*/

void		lemin_debug(t_lemin *lemin, t_ant *ant, t_room *room)
{
	int		i;

	i = 0;
	usleep(DEBUG_SLEEP);
	ft_mini_printf("\n\n");
	while (i < ANT_HEIGHT)
	{
		ft_mini_printf("%s", g_ant[lemin->param.debug % 3][i], LIGHT_YELLOW);
		i += 1;
	}
	ft_mini_printf("\n");
	ft_mini_printf("Ant  id   : %d\n", ant->id, LIGHT_YELLOW);
	ft_mini_printf("Room name : %d\n", room->flag, LIGHT_RED);
	ft_mini_printf("Room flag : %d\n", room->flag, LIGHT_RED);
	ft_mini_printf("L%d-%s \n", ant->id, LIGHT_YELLOW, \
					ant->room->name, LIGHT_RED);
	lemin->param.debug += 1;
	return ;
}
