

#include "lemin.h"

void	destroy_room(void *data)
{
	t_room		*room;

	room = (t_room *)data;
	ft_strdel(&room->name);
	ft_lst_rec_free(room->paths);
	free(data);
	data = NULL;
}

void	destroy_path(void *data)
{
	t_path		*path;

	path = (t_path *)data;
	ft_strdel(&path->door1);
	ft_strdel(&path->door2);
	free(data);
	data = NULL;
}

void	destroy_everything(t_list *rooms, t_list *paths, int error)
{
	if (rooms)
	{
		ft_lstforeach(rooms, destroy_room);
		ft_lst_rec_free(rooms);
	}
	if (paths)
	{
		ft_lstforeach(paths, destroy_path);
		ft_lst_rec_free(paths);
	}
	if (error)
		printf("ERROR\n");
	exit (0);
}
