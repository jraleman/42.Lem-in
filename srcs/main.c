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

t_lemin		*lemin_init(void)
{
		t_lemin *init;

		//init->ants_total = 0;

		//init->ants_list = NULL;

		if (!(init = (t_lemin *)malloc(sizeof(t_lemin))))
				ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);

		init->ants_total = lemin_ants();
		if (init->ants_total == 0)
		{
			lemin_end(init->rooms_list, init->paths_list);
			ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
		}

		init->rooms_list = NULL;
		init->paths_list = NULL;
		if (lemin_read(&init->rooms_list, &init->paths_list) == ERROR)
			exit(-1);
		if (!init->rooms_list || !init->paths_list)
		{
			lemin_end(init->rooms_list, init->paths_list);
			ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
		}
		init->ants_list = init_ants(init->ants_total, init->rooms_list);
		return (init);
}

/*
** Let's rock and roll!
*/

int			main(void)
{

	t_lemin	*lemin;

	lemin = lemin_init();
	//lemin_print(rooms_list, paths_list, ants_total);
	lemin_print(lemin->rooms_list, lemin->paths_list, lemin->ants_total);


	// check this one out
	//drill(rooms_list, paths_list);
	drill(lemin->rooms_list, lemin->paths_list);


	if (lemin_validate(lemin->rooms_list, lemin->paths_list) != TRUE)
	{
		lemin_end(lemin->rooms_list, lemin->paths_list);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}



	game_loop(lemin->ants_list, lemin->ants_total, lemin->rooms_list, lemin->paths_list);
	return (0);
}
