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

////////////////////////////////////////////////////////////////////////////////
// GET_PARAMS.C
////////////////////////////////////////////////////////////////////////////////

void invalid_param(char *param, char *program)
{
   // Argument: [*param] is invalid.
	 // See (program --help || -h)
   //ft_puterror_fd()
	 return ;
}


void print_help(void)
{
	  // about lemin, how to use it, params, map_pages
	  return ;
}

// bonus
// man page!!!!
void get_params(int total_params, char *params[], lemin *init)
{
		int		i;

		i = 1;
		while (--total_params)
		{
			if (params[i] == "--help" || params[i] == "-h")
				// print_help();
			else if (params[i] == "--debug" || params[i] == "-d")
				// init->param.debug = 1;
			else if (params[i] == "--path" || params[i] == "-p")
				// init->param.path = 1;
			else if (params[i] == "--room" || params[i] == "-r")
				// init->param.room = 1;
			else if (params[i] == "--ant" || params[i] == "-a")
				// init->param.ant = 1;
			else
			  // invalid_param(params[i], params[0]);
			i += 1
		}
		return ;
}

////////////////////////////////////////////////////////////////////////////////

/*
** Let's rock and roll!
*/

int   main(int argc, char *argv[])
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
