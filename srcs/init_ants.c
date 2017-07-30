/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:47:43 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 01:47:44 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Initialize the ants.
*/

t_ant		*init_ants(int total_ants, t_list *rooms)
{
	int		i;
	t_ant	*ants;

	i = 0;
	if (!(ants = (t_ant *)malloc(sizeof(t_ant) * total_ants)))
		ft_puterror_fd("Memory allocation failed.", MALLC_ERR, FT_STD_ERR);
	while (i < total_ants)
	{
		ants[i].room = get_room_flag(STARTROOM, rooms);
		ants[i].did_turn = 0;
		ants[i].id = i + 1;
		i += 1;
	}
	return (ants);
}
