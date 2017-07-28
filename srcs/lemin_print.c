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
** ...
*/

static void	print_room(void *room)
{
	t_room		*tmp;

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
	printf("%s %d %d\n", tmp->name,
							tmp->x, tmp->y);
	return ;
}

/*
** ...
*/

static void	print_path(void *tunnel)
{
	t_path		*path;

	path = (t_path *)tunnel;
	printf("%s-%s\n", path->door1, path->door2);
	return ;
}

/*
** ...
*/

void lemin_print(t_list *rooms, t_list *paths, int ants)
{
	printf("%d\n", ants);
	ft_lstforeach(rooms, print_room);
	ft_lstforeach(paths, print_path);
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}