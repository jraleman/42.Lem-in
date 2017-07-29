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

	if (room != NULL)
	{
		tmp = (t_room *)room;
		if (tmp->flag == STARTROOM)
			ft_putendl_fd("##start", FT_STD_OUT);
		else if (tmp->flag == ENDROOM)
			ft_putendl_fd("##end", FT_STD_OUT);
		ft_mini_printf("%s %d %d", tmp->name, 39, tmp->x, 39, tmp->y, 39);
	}
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}

/*
** Print the paths.
*/

static void	print_path(void *tunnel)
{
	t_path	*path;

	path = (t_path *)tunnel;
	ft_mini_printf("%s-%s\n", path->door1, 39, path->door2, 39);
	return ;
}

/*
** Print the paths.
*/

static void	print_room_colored(void *room)
{
	t_room	*tmp;

	if (room != NULL)
	{
		tmp = (t_room *)room;
		if (tmp->flag == STARTROOM)
			ft_putendl_fd("##start", FT_STD_OUT);
		else if (tmp->flag == ENDROOM)
			ft_putendl_fd("##end", FT_STD_OUT);
		ft_mini_printf("%s %d %d", tmp->name, 91, tmp->x, 93, tmp->y, 93);
	}
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}

/*
** Print the rooms.
*/

static void	print_path_colored(void *tunnel)
{
	t_path	*path;

	path = (t_path *)tunnel;
	ft_mini_printf("%s-%s\n", path->door1, 36, path->door2, 36);
	return ;
}

/*
** Print to the stdout the rooms and paths.
*/

void		lemin_print(t_lemin *lemin)
{
	if (lemin->param.ant_colored == FALSE)
		ft_mini_printf("%d\n", lemin->ants_total, 39);
	else
		ft_mini_printf("%d\n", lemin->ants_total, 93);
	if (lemin->param.path_colored == FALSE)
		ft_lstforeach(lemin->paths_list, print_path);
	else
		ft_lstforeach(lemin->paths_list, print_path_colored);
	if (lemin->param.room_colored == FALSE)
		ft_lstforeach(lemin->rooms_list, print_room);
	else
		ft_lstforeach(lemin->rooms_list, print_room_colored);
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}
