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

char const	g_logo[LOGO_HEIGHT][LOGO_WIDTH] =
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
	ft_mini_printf("\n%s\n", g_logo[0], LIGHT_GREEN);
	ft_mini_printf("Lemin reads from the standard input. \n");
	ft_mini_printf("You may write line by or feed in a file, like this:\n");
	ft_mini_printf("%s < test.map\n", progname, LIGHT_BLUE);
	ft_mini_printf("Your may add the following arguments for: \n");
	ft_mini_printf("    -m | --man    -> view the man page\n");
	ft_mini_printf("    -a | --ant    -> color the ants\n");
	ft_mini_printf("    -p | --path   -> color the paths\n");
	ft_mini_printf("    -r | --room   -> color the rooms\n");
	ft_mini_printf("    -d | --debug  -> for debugging purposes\n");
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

static void	display_manpage(void)
{
	int		ret;

	ret = system("man ./resources/lemin.man");
	exit(ret);
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
	init->param.debug = FALSE;
	init->param.ant_colored = FALSE;
	init->param.path_colored = FALSE;
	init->param.room_colored = FALSE;
	while (--argc)
	{
		if (ft_strequ(argv[i], "-h") || ft_strequ(argv[i], "--help"))
			print_help(argv[0]);
		else if (ft_strequ(argv[i], "-m") || ft_strequ(argv[i], "--man"))
			display_manpage();
		else if (ft_strequ(argv[i], "-d") || ft_strequ(argv[i], "--debug"))
			init->param.debug = TRUE;
		else if (ft_strequ(argv[i], "-a") || ft_strequ(argv[i], "--ant"))
			init->param.ant_colored = TRUE;
		else if (ft_strequ(argv[i], "-p") || ft_strequ(argv[i], "--path"))
			init->param.path_colored = TRUE;
		else if (ft_strequ(argv[i], "-r") || ft_strequ(argv[i], "--room"))
			init->param.room_colored = TRUE;
		else
			invalid_param(argv[i], argv[0]);
		i += 1;
	}
	return ;
}
