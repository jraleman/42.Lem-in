/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:22:51 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 05:22:52 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


int		can_move(t_ant *ant)
{
	t_list		*ls;
	t_room		*tmp;
	int			yes;
	int			may_move;

	if (ant->room->flag == ENDROOM)
		return (0);
	yes = 1;
	may_move = 0;
	if (ant->did_turn)
		yes = 0;
	ls = ant->room->paths;
	while (yes && ls)
	{
		tmp = (t_room *)ls->content;
		if ((!tmp->has_ant && !(tmp->flag == STARTROOM) && tmp != ant->last)
			|| tmp->flag == ENDROOM)
		{
			may_move = 1;
			break ;
		}
		ls = ls->next;
	}
	return (yes && may_move);
}

static int	game_over(t_ant *ants, int antnum)
{
	int		i;

	if (!ants)
		return (1);
	i = 0;
	while (i < antnum)
	{
		if (ants[i].room->flag != ENDROOM)
			return (0);
		i++;
	}
	return (1);
}


void	reset_ants(t_ant *ants, int antnum)
{
	int		i;

	i = 0;
	while (i < antnum)
	{
		ants[i].did_turn = 0;
		i++;
	}
}


void		lemin_loop(t_lemin *lemin, t_ant *ants)
{
	int		i;
	int		turn_ended;

	while (!game_over(ants, lemin->ants_total))
	{
		turn_ended = 0;
		reset_ants(ants, lemin->ants_total);
		while (!turn_ended && !game_over(ants, lemin->ants_total))
		{
			turn_ended = 1;
			i = 0;
			while (i < lemin->ants_total)
			{
				if (can_move(ants + i))
				{
					play(ants + i);
					turn_ended = 0;
				}
				i += 1;
			}
			ft_putchar_fd('\n', FT_STD_OUT);
		}
	}
	lemin_end(lemin);
}
