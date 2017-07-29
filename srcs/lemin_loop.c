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
** ...
*/

static int	can_move(t_ant *ant)
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
** ...
*/

static int	game_over(t_ant *ants, int antnum)
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
** ...
*/

static void	move_ants(t_lemin *lemin)
{
	int		i;

	while (!game_over(lemin->ants_list, lemin->ants_total))
	{
		i = 0;
		while (i < lemin->ants_total)
		{
			if (can_move(lemin->ants_list + i))
			{
				lemin->ants_list += i;
				lemin_play(lemin);
				lemin->ants_list -= i;
				ft_putchar_fd('\n', FT_STD_OUT);
				return ;
			}
			i += 1;
		}
		ft_putchar_fd('\n', FT_STD_OUT);
	}
	return ;
}

/*
** ...
*/

void		lemin_loop(t_lemin *lemin)
{
	while (!game_over(lemin->ants_list, lemin->ants_total))
	{
		reset_ants(lemin->ants_list, lemin->ants_total);
		move_ants(lemin);
	}
	lemin_end(lemin);
	return ;
}
