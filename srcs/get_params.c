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
** Prints the lemin logo.
*/

static void	print_logo(void)
{
	printf("    _     U _____ u  __  __              _   _    \n");
	printf("   |.|    \\| ___.|/U|. \\/ .|u   ___     | \\ |.|   \n");
	printf(" U | | u   |  __|  \\| |\\/| |/  |_._|   <|  \\| |>  \n");
	printf("  \\| |/__  | |___   | |  | |    | |    U| |\\  |u  \n");
	printf("   |_____| |_____|  |_|  |_|  U/| |\\u   |_| \\_|   \n");
	printf("   //  \\\\  <<   >> <<,-,,-..-,_|___|_,-.||   \\\\,-.\n");
	printf("  (_^)(^_)(__) (__) (./  \\.)\\_)-' '-(_/ (_^)  (_/ \n\n");
	return ;
}

/*
** Prints the help message.
*/

static void	print_help(char *progname)
{
	print_logo();
	printf("The goal of this project is to find the quickest way to get n ");
	printf("ants across the farm.\n");
	printf("Lemin reads from the standard input. You may write line by ");
	printf("or feed in a file, like this:\n");
	printf("%s < test.map\n", progname);
	exit(0);
	return ;
}

/*
** Prints the invalid argument, and exits the program.
*/

static void	invalid_param(char *arg, char *progname)
{
	printf("Argument %s is invalid!\n", arg);
	printf("Run %s -h or --help to know how to run this shit. :)\n", progname);
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
