/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 03:44:41 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/27 03:44:41 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"






void	print_room(void *room)
{
	t_room		*tmp;

	if (!room)
	{
		write(1, "\n", 1);
		return ;
	}
	tmp = (t_room *)room;
	if (tmp->flag == STARTROOM)
		printf("##start\n");
	else if (tmp->flag == ENDROOM)
		printf("##end\n");
	printf("%s %d %d\n", tmp->name,
							tmp->x, tmp->y);
}

void	print_path(void *tunnel)
{
	t_path		*path;

	path = (t_path *)tunnel;
	printf("%s-%s\n", path->door1, path->door2);
}

















int			main(void)
{
	int			total_ants;
	t_list		*rooms;
	t_list		*paths;
	t_ant		*ants;

	rooms = NULL;
	paths = NULL;
	if (!(total_ants = lemin_get_total_ants()) || total_ants == 0)
		printf("ERROR\n");
	else
	{

		//printf("%d\n", total_ants);

		if (lemin_read_input(&rooms, &paths) == ERROR)
			exit(-1);





		if (!rooms || !paths)
			destroy_everything(rooms, paths, 1);

		ants = init_ants(total_ants, rooms);


		printf("%d\n", total_ants);
		ft_lstforeach(rooms, print_room);
		ft_lstforeach(paths, print_path);
		write(1, "\n", 1);


		drill(rooms, paths);
		valid_or_die(rooms, paths);

		game_loop(ants, total_ants, rooms, paths);
	}
	return (0);
}
