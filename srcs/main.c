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
	if (!(total_ants = lemin_ants()))
	{
		lemin_end(rooms, paths);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}
	else
	{

		//printf("%d\n", total_ants);

		if (lemin_read(&rooms, &paths) == ERROR)
			exit(-1);





		if (!rooms || !paths)
		{
			lemin_end(rooms, paths);
			ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
		}


		ants = init_ants(total_ants, rooms);


		printf("%d\n", total_ants);
		ft_lstforeach(rooms, print_room);
		ft_lstforeach(paths, print_path);
		write(1, "\n", 1);


		drill(rooms, paths);
		if (lemin_validate(rooms, paths) != TRUE)
		{
			lemin_end(rooms, paths);
			ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
		}



		game_loop(ants, total_ants, rooms, paths);
	}
	return (0);
}
