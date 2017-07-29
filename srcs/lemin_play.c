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
		{"    \\_/   "},
		{"   '-0-'   "},
		{"   --0--   "},
		{"   .-0-.   "},
	},
	{
		{"      \\_/ "},
		{"    '-0-'  "},
		{"   --0--   "},
		{"   .-0-.   "},
	},
	{
		{"  \\_/     "},
		{"  '-0-'    "},
		{"   --0--   "},
		{"   .-0-.   "},
	}
};

/*
** ...
*/

//static void	print_ant()

/*
** ...
*/

static void	move_ants(t_ant *ant, t_room *room)
{
	ant->room->has_ant = 0;
	ant->last = ant->room;
	ant->room = room;
	ant->room->has_ant = 1;
	ft_mini_printf("L%d-%s ", ant->id, 39, ant->room->name, 39);
}

/*
** ...
*/

void		lemin_play(t_lemin *lemin)
{
	t_list	*ls;
	t_room	*tmp;
	t_room	*next;
	int		distance;
	int		result;

	int		i;

	i = 0;

	// INT_MAX (START FROM THE BIGGEST NUMBER)
	distance = 2147483647;
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


			//printf("L%d-%s\n", lemin->ants_list->id, next->name);
			i += 1;
	}
	if (distance < 2147483647)
		move_ants(lemin->ants_list, next);


/*
	sleep(1);
	int 	i;
	i = 0;
	while (i < ANT_HEIGHT)
	{
		ft_mini_printf("%s", g_ant[lemin->param.debug % 3][i++]);
	}
	lemin->param.debug += 1;
*/

}
