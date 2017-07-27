

#include "lemin.h"

t_room	*init_room(char *line, int room_flag)
{
	t_room		*newroom;
	int			i;

	i = 0;
	newroom = malloc(sizeof(t_room));
	if (!newroom)
		return (NULL);
	while (line[i] != ' ')
		i++;
	newroom->flag = room_flag;
	newroom->name = ft_strsub(line, 0, i);
	while (line[i] == ' ')
		i++;
	newroom->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	newroom->y = ft_atoi(line + i);
	newroom->paths = NULL;
	newroom->busy = 0;
	newroom->has_ant = 0;
	free(line);
	return (newroom);
}

t_path	*init_path(char *line)
{
	t_path		*newpath;
	int			score_pos;

	newpath = malloc(sizeof(t_path));
	if (!newpath)
		return (NULL);
	score_pos = (int)ft_strlchr(line, '-');
	newpath->door1 = ft_strsub(line, 0, score_pos);
	newpath->door2 = ft_strdup(line + score_pos + 1);
	free(line);
	return (newpath);
}

t_ant	*init_ants(int antnum, t_list *rooms)
{
	t_ant	*ants;
	int		i;

	i = 0;
	ants = malloc(sizeof(t_ant) * antnum);
	if (!ants)
		return (NULL);
	while (i < antnum)
	{
		ants[i].room = get_room_by_flag(STARTROOM, rooms);
		ants[i].did_turn = 0;
		ants[i].id = i + 1;
		i++;
	}
	return (ants);
}
