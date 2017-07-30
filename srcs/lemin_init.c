/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 00:17:20 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 00:17:21 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Initialize the lemin structure.
*/

t_lemin		*lemin_init(int total_params, char *params[])
{
	t_lemin	*init;

	if (!(init = (t_lemin *)malloc(sizeof(t_lemin))))
		ft_puterror_fd("Memory allocation failed!", MALLC_ERR, FT_STD_ERR);
	init->room_list = NULL;
	init->path_list = NULL;
	get_params(total_params, params, init);
	if ((init->ant_total = get_ant_total()) == FALSE)
	{
		lemin_end(init);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}
	if (lemin_read(init) == ERROR)
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	if (!init->room_list || !init->path_list)
	{
		lemin_end(init);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}
	init->ant_list = init_ants(init->ant_total, init->room_list);
	return (init);
}
