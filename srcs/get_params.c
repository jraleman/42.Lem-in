/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 18:37:15 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 18:37:16 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ...
*/

static void	print_help(void)
{
	printf("HILFE\n");
	exit(0);
	return ;
}

/*
** ...
*/

static void	invalid_param(char *param, char *program)
{
	printf("Argument %s is invalid!\n", param);
	printf("Run %s -h or --help to know how to run this shit. :)\n", program);
	exit(PARAM_ERR);
	return ;
}

/*
** ...
** do the man page!!!
*/

void		get_params(int argc, char *argv[], t_lemin *init)
{
	int	i;

	i = 1;
	while (--argc)
	{
		if (ft_strequ(argv[i], "-h") || ft_strequ(argv[i], "--help"))
			print_help();
		else if (ft_strequ(argv[i], "-a") || ft_strequ(argv[i], "--ant"))
			init->param.ant = TRUE;
		else if (ft_strequ(argv[i], "-p") || ft_strequ(argv[i], "--path"))
			init->param.path = TRUE;
		else if (ft_strequ(argv[i], "-r") || ft_strequ(argv[i], "--room"))
			init->param.room = TRUE;
		else if (ft_strequ(argv[i], "-d") || ft_strequ(argv[i], "--debug"))
			init->param.debug = TRUE;
		else
			invalid_param(argv[i], argv[0]);
		i += 1;
	}
	return ;
}
