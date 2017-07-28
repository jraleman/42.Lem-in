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

int			main(void)
{

	// t_lemin	lemin;
	// lemin = lemin_init();
	// lemin_print(lemin->rooms_list, lemin->paths_list, lemin.ants_total);

////////////////////////////////////////////////////////////////////////////////
// Lemin init()
////////////////////////////////////////////////////////////////////////////////
	int			ants_total;
	t_list		*rooms_list;
	t_list		*paths_list;
	t_ant		*ants;

	rooms_list = NULL;
	paths_list = NULL;
	if (!(ants_total = lemin_ants()))
	{
		lemin_end(rooms_list, paths_list);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}

		if (lemin_read(&rooms_list, &paths_list) == ERROR)
			exit(-1);
		if (!rooms_list || !paths_list)
		{
			lemin_end(rooms_list, paths_list);
			ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
		}
		ants = init_ants(ants_total, rooms_list);

////////////////////////////////////////////////////////////////////////////////

	lemin_print(rooms_list, paths_list, ants_total);

	// check this one out
	drill(rooms_list, paths_list);



	if (lemin_validate(rooms_list, paths_list) != TRUE)
	{
		lemin_end(rooms_list, paths_list);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}



	game_loop(ants, ants_total, rooms_list, paths_list);
	return (0);
}
