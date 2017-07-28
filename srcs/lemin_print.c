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

static void	print_room(void *room)
{
	t_room	*tmp;

	if (!room)
	{
		ft_putchar_fd('\n', FT_STD_OUT);
		return ;
	}
	tmp = (t_room *)room;
	if (tmp->flag == STARTROOM)
		printf("##start\n");
	else if (tmp->flag == ENDROOM)
		printf("##end\n");
	printf("%s %d %d\n", tmp->name, tmp->x, tmp->y);
	return ;
}

/*
** Print the paths.
*/

static void	print_path(void *tunnel)
{
	t_path	*path;

	path = (t_path *)tunnel;
	printf("%s-%s\n", path->door1, path->door2);
	return ;
}

/*
** Print to the stdout the rooms and paths.
*/

void		lemin_print(t_lemin *lemin)
{
	printf("%d\n", lemin->ants_total);
	ft_lstforeach(lemin->rooms_list, print_room);
	ft_lstforeach(lemin->paths_list, print_path);
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}
