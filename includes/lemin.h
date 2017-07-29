/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 00:29:13 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 00:29:14 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdio.h>

/*
** ...
*/

# define STARTROOM 		(1)
# define NORMAL 		(2)
# define ENDROOM		(3)

/*
** ...
*/

# define ERROR			(-1)
# define PARAM_ERR		(-2)
# define MALLC_ERR		(-3)

/*
** ...
*/

# define FT_STD_INT		(0)
# define FT_STD_OUT		(1)
# define FT_STD_ERR		(2)

/*
** ...
*/

# define LIGHT_RED		(91)
# define LIGHT_GREEN	(92)

/*
** ...
*/

# define LOGO_WIDTH		(51)
# define LOGO_HEIGHT	(7)

/*
** Global variables
*/

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

extern int		g_logo[LOGO_HEIGHT][LOGO_WIDTH];

# endif

/*
** ...
*/

typedef struct	s_path
{
	char		*door1;
	char		*door2;
}				t_path;

/*
** ...
*/

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int			flag;
	int			busy;
	int			has_ant;
	t_list		*paths;
}				t_room;

/*
** ...
*/

typedef struct	s_ant
{
	int			id;
	t_room		*room;
	t_room		*last;
	int			did_turn;
}				t_ant;

/*
** ...
*/

typedef struct	s_param
{
	int			debug;
	int			path;
	int			room;
	int			ant;
}				t_param;

/*
** ...
*/

typedef struct	s_lemin
{
	int			ants_total;
	t_ant		*ants_list;
	t_list		*rooms_list;
	t_list		*paths_list;
	t_param		param;
}				t_lemin;

/*
** ...
*/

int				lemin_read(t_lemin *lemin);
int				lemin_validate(t_lemin *lemin);
void			lemin_end(t_lemin *lemin);
void			lemin_loop(t_lemin *lemin);
void			lemin_play(t_lemin *lemin);
void			lemin_start(t_lemin *lemin);
void			lemin_print(t_lemin *lemin);
t_lemin			*lemin_init(int total_params, char *params[]);

/*
** ...
*/

int				find_room(void *room, int flag);

/*
** ...
*/

int				get_ants_total(void);
void			get_params(int argc, char *argv[], t_lemin *init);
t_room			*get_room_name(char *name, t_list *list);
t_room			*get_room_flag(int flag, t_list *list);

/*
** ...
*/

t_ant			*init_ants(int total_ants, t_list *rooms);
t_path			*init_path(char *line);
t_room			*init_room(char *line, int room_flag);

#endif
