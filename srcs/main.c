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

/*
** Let's rock and roll!
*/

int			main(int argc, char *argv[])
{
	t_lemin	*lemin;

	lemin = lemin_init(argc, argv);
	lemin_print(lemin);
	lemin_start(lemin);
	if (lemin_validate(lemin) != TRUE)
	{
		lemin_end(lemin);
		ft_puterror_fd("Error :(", ERROR, FT_STD_ERR);
	}
	lemin_loop(lemin);
	return (0);
}
