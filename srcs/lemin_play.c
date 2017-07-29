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

/*
** ...
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
** ...
*/

static void	print_debug(t_lemin *lemin, t_ant *ant, t_room *room)
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

/*
** ...
*/

static void	print_ant(t_lemin *lemin, t_ant *ant, t_room *room)
{
	if (lemin->param.debug == FALSE)
		ft_mini_printf("L%d-%s ", ant->id, 0, ant->room->name, 0);
	else
		print_debug(lemin, lemin->ants_list, room);
	return ;
}

/*
** ...
*/

static void	move_ants(t_lemin *lemin, t_ant *ant, t_room *room)
{
	ant->room->has_ant = 0;
	ant->last = ant->room;
	ant->room = room;
	ant->room->has_ant = 1;
	print_ant(lemin, ant, room);
	return ;
}

/*
** ...
*/

void		lemin_play(t_lemin *lemin)
{
	int		result;
	int		distance;
	t_list	*ls;
	t_room	*tmp;
	t_room	*next;

	distance = FT_INT_MAX;
	ls = lemin->ants_list->room->paths;
	while (ls)
	{
		tmp = (t_room *)ls->content;
		if ((tmp->flag == ENDROOM || !tmp->has_ant) \
				&& tmp != lemin->ants_list->last)
		{
			result = find_room(tmp, ENDROOM);
			if (result < distance && result > -1)
			{
				distance = result;
				next = tmp;
			}
		}
		ls = ls->next;
	}
	if (distance < FT_INT_MAX)
		move_ants(lemin, lemin->ants_list, next);
}
