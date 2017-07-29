/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:58:54 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/27 16:58:55 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Print the rooms.
*/

static void	print_room(t_lemin room)
{
	t_room 	*tmp;

	if (room.rooms_list == NULL)
	{
		ft_putchar_fd('\n', FT_STD_OUT);
		return ;
	}
	tmp = (t_room *)room.rooms_list;
	if (tmp->flag == STARTROOM)
		printf("##start\n");
	else if (tmp->flag == ENDROOM)
		printf("##end\n");
	//if ()
	ft_mini_printf("%s %d %d\n", tmp->name, 91, tmp->x, 91, tmp->y, 91);
	return ;
}

/*
** Print the paths.
*/

static void	print_path(t_lemin tunnel)
{
	t_path 	*path;

	path = (t_path *)tunnel.rooms_list;
	ft_mini_printf("%s-%s\n", path->door1, 36, path->door2, 36);
	return ;
}

/*
** Print to the stdout the rooms and paths.
*/

void		lemin_print(t_lemin *lemin)
{
	ft_mini_printf("%d\n", lemin->ants_total);
	ft_lstforeach(lemin->rooms_list, print_room);
	ft_lstforeach(lemin->paths_list, print_path);
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}

//ft_lstforeach(lemin, print_room);
//path = (t_path *)tunnel->paths_list;
