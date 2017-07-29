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
** Lemin logo.
*/

char g_logo[LOGO_HEIGHT][LOGO_WIDTH] =
{
	{"    _     U _____ u  __  __              _   _    \n"},
	{"   |.|    \\| ___.|/U|. \\/ .|u   ___     | \\ |.|   \n"},
	{" U | | u   |  __|  \\| |\\/| |/  |_._|   <|  \\| |>  \n"},
	{"  \\| |/__  | |___   | |  | |    | |    U| |\\  |u  \n"},
	{"   |_____| |_____|  |_|  |_|  U/| |\\u   |_| \\_|   \n"},
	{"   //  \\\\  <<   >> <<,-,,-..-,_|___|_,-.||   \\\\,-.\n"},
	{"  (_^)(^_)(__) (__) (./  \\.)\\_)-' '-(_/ (_^)  (_/ \n"}
};

/*
** Prints the help message.
*/

static void	print_help(char *progname)
{
	ft_mini_printf("%s", g_logo[0], LIGHT_GREEN);
	ft_mini_printf("The goal of this project is to find the quickest way" \
					" to get n ants across the farm.\n");
	ft_mini_printf("Lemin reads from the standard input." \
					"You may write line by or feed in a file, like this:\n");
	ft_mini_printf("%s < test.map\n", progname, 91);
	ft_mini_printf("Your may add the following arguments for: \n");
	ft_mini_printf("-a || --ant   : color the ants");
	ft_mini_printf("-p || --path  : color the paths");
	ft_mini_printf("-r || --room  : color the rooms");
	ft_mini_printf("-d || --debug : for debugging purposes");
	exit(0);
	return ;
}

/*
** Prints the invalid argument, and exits the program.
*/

static void	invalid_param(char *arg, char *progname)
{
	ft_mini_printf("Argument %s is invalid!\n", arg);
	ft_mini_printf("Run %s -h or --help to know how " \
					"to run this shit. :)\n", progname);
	exit(PARAM_ERR);
	return ;
}

/*
** ...
** do the man page!!!
*/

void		get_params(int argc, char *argv[], t_lemin *init)
{
	int		i;

	i = 1;
	while (--argc)
	{
		if (ft_strequ(argv[i], "-h") || ft_strequ(argv[i], "--help"))
			print_help(argv[0]);
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
