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

/*
** Check if an ant can move to a room.
*/

static int	check_move(t_ant *ant)
{
	int		yes;
	int		may_move;
	t_list	*ls;
	t_room	*tmp;

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

/*
** Checks if the lemin loop should end..
*/

static int	end_loop(t_ant *ants, int antnum)
{
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (i < antnum && ants != 0)
	{
		if (ants[i].room->flag != ENDROOM)
		{
			ret = 0;
			break ;
		}
		i += 1;
	}
	return (ret);
}

/*
** Reset the ants status (if they have turned).
*/

static void	reset_ants(t_ant *ants, int antnum)
{
	int		i;

	i = 0;
	while (i < antnum)
	{
		ants[i].did_turn = 0;
		i += 1;
	}
	return ;
}

/*
** Check the ants, sand see if they can move.
*/

static void	check_ants(t_lemin *lemin)
{
	int		i;
	int		turn;

	turn = 0;
	while (!turn && !end_loop(lemin->ant_list, lemin->ant_total))
	{
		i = 0;
		turn = 1;
		while (i < lemin->ant_total)
		{
			if (check_move(lemin->ant_list + i))
			{
				turn = 0;
				lemin->ant_list += i;
				lemin_play(lemin);
				lemin->ant_list -= i;
			}
			i += 1;
		}
		ft_putchar_fd('\n', FT_STD_OUT);
	}
	return ;
}

/*
** Loop through
*/

void		lemin_loop(t_lemin *lemin)
{
	while (!end_loop(lemin->ant_list, lemin->ant_total))
	{
		reset_ants(lemin->ant_list, lemin->ant_total);
		check_ants(lemin);
	}
	if (lemin->param.debug == TRUE)
		ft_mini_printf("\nNumber of moves : %d\n", lemin->moves, LIGHT_GREEN);
	lemin_end(lemin);
	return ;
}
