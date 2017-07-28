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

# define STARTROOM 	(1)
# define NORMAL 		(2)
# define ENDROOM		(3)

/*
** ...
*/

# define ERROR			(-1)

/*
** ...
*/

# define FT_STD_INT		(0)
# define FT_STD_OUT		(1)
# define FT_STD_ERR		(2)

/*
** ...
*/

typedef struct	s_path
{
	char			*door1;
	char			*door2;
}				t_path;

/*
** ...
*/

typedef struct		s_room
{
	char		*name;
	int				x;
	int				y;
	int				flag;
	int				busy;
	int				has_ant;
	t_list			*paths;
}				t_room;

/*
** ...
*/

typedef struct		s_ant
{
	int			id;
	t_room			*room;
	t_room			*last;
	int				did_turn;
}				t_ant;

/*
** ...
*/

typedef struct	s_lemin
{
	int				ants_total;
	t_ant			*ants_list;
	t_list 			*rooms_list;
	t_list 			*paths_list;
}				t_lemin;








int					lemin_read(t_list **rooms, t_list **paths);
int					lemin_validate(t_list *rooms, t_list *paths);

void 				lemin_print(t_list *rooms, t_list *paths, int ants);
void				lemin_end(t_list *rooms, t_list *paths);



int					get_ants_total(void);

t_lemin				*lemin_init(void);

t_ant				*init_ants(int antnum, t_list *rooms);
t_path				*init_path(char *line);
t_room				*init_room(char *line, int room_flag);






//void				destroy_everything(t_list *rooms, t_list *paths, int error);
void				drill(t_list *rooms, t_list *paths);
int					find(void *room, int flag);
void				game_loop(t_ant *ants, int antnum, t_list *r, t_list *p);
t_room				*get_room_by_name(char *name, t_list *list);
t_room				*get_room_by_flag(int flag, t_list *list);




void				move(t_ant *ant, t_room *room);
//void				print_room(void *room);
void				print_room_paths(t_room *room);
void				reset_ants(t_ant *ants, int antnum);


#endif
