

#include "lemin.h"

void	reset_ants(t_ant *ants, int antnum)
{
	int		i;

	i = 0;
	while (i < antnum)
	{
		ants[i].did_turn = 0;
		i++;
	}
}

int		unique_flags(t_list *rooms)
{
	int			starts_found;
	int			ends_found;
	t_room		*tmp;

	starts_found = 0;
	ends_found = 0;
	while (rooms)
	{
		tmp = (t_room *)rooms->content;
		if (tmp->flag == STARTROOM)
			starts_found++;
		if (tmp->flag == ENDROOM)
			ends_found++;
		rooms = rooms->next;
	}
	if (starts_found != 1)
		return (0);
	if (ends_found != 1)
		return (0);
	return (1);
}

int		path_exists(t_room *startroom)
{
	int		debug;

	debug = find(startroom, ENDROOM);
	if (debug < 0 || debug == 2147483647)
		return (0);
	return (1);
}

void	valid_or_die(t_list *rooms, t_list *paths)
{
	int		ret;

	ret = 1;
	if ((!rooms || !paths))
		ret = 0;
	else if (!unique_flags(rooms))
		ret = 0;
	else if (!path_exists(get_room_by_flag(STARTROOM, rooms)))
		ret = 0;
	if (!ret)
		destroy_everything(rooms, paths, 1);
}
