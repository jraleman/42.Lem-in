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
	t_room	*tmp_room;

	if (room != NULL)
	{
		tmp_room = (t_room *)room;
		if (tmp_room->flag == STARTROOM)
			ft_putendl_fd("##start", FT_STD_OUT);
		else if (tmp_room->flag == ENDROOM)
			ft_putendl_fd("##end", FT_STD_OUT);
		ft_putstr_fd(tmp_room->name, FT_STD_OUT);
		ft_putchar_fd(' ', FT_STD_OUT);
		ft_putnbr_fd(tmp_room->x, FT_STD_OUT);
		ft_putchar_fd(' ', FT_STD_OUT);
		ft_putnbr_fd(tmp_room->y, FT_STD_OUT);
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
	ft_putstr_fd(path->door1, FT_STD_OUT);
	ft_putchar_fd('-', FT_STD_OUT);
	ft_putendl_fd(path->door2, FT_STD_OUT);
	return ;
}

/*
** Print the rooms (colored).
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
		ft_mini_printf("%s %d %d", tmp->name, LIGHT_RED, \
						tmp->x, LIGHT_GREEN, tmp->y, LIGHT_GREEN);
	}
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}

/*
** Print the paths (colored).
*/

static void	print_path_colored(void *tunnel)
{
	t_path	*path;

	path = (t_path *)tunnel;
	ft_mini_printf("%s-%s\n", path->door1, LIGHT_BLUE, \
					path->door2, LIGHT_BLUE);
	return ;
}

/*
** Print to the stdout the rooms and paths.
*/

void		lemin_print(t_lemin *lemin)
{
	if (lemin->param.ant_colored != TRUE)
		ft_putnbr_fd(lemin->ant_total, FT_STD_OUT);
	else
		ft_mini_printf("%d", lemin->ant_total, LIGHT_YELLOW);
	ft_putchar_fd('\n', FT_STD_OUT);
	if (lemin->param.room_colored != TRUE)
		ft_lstforeach(lemin->room_list, print_room);
	else
		ft_lstforeach(lemin->room_list, print_room_colored);
	if (lemin->param.path_colored != TRUE)
		ft_lstforeach(lemin->path_list, print_path);
	else
		ft_lstforeach(lemin->path_list, print_path_colored);
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}
