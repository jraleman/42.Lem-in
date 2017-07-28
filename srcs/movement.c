

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


int		can_move(t_ant *ant)
{
	t_list		*ls;
	t_room		*tmp;
	int			yes;
	int			may_move;

	if (ant->room->flag == ENDROOM)
		return (0);
	yes = 1;
	may_move = 0;
	if (ant->did_turn)
		yes = 0;
	ls = ant->room->paths;
	while (yes && ls)
	{
		tmp = (t_room *)ls->content;
		if ((!tmp->has_ant && !(tmp->flag == STARTROOM) && tmp != ant->last)
			|| tmp->flag == ENDROOM)
		{
			may_move = 1;
			break ;
		}
		ls = ls->next;
	}
	return (yes && may_move);
}

void	play(t_ant *ant)
{
	t_list		*ls;
	t_room		*tmp;
	t_room		*next;
	int			distance;
	int			result;

	distance = 2147483647;
	ls = ant->room->paths;
	while (ls)
	{
		tmp = (t_room *)ls->content;
		if ((tmp->flag == ENDROOM || !tmp->has_ant) && tmp != ant->last)
		{
			result = find(tmp, ENDROOM);
			if (result < distance && result > -1)
			{
				distance = result;
				next = tmp;
			}
		}
		ls = ls->next;
	}
	if (distance < 2147483647)
		move(ant, next);
}

void	move(t_ant *ant, t_room *room)
{
	ant->room->has_ant = 0;
	ant->last = ant->room;
	ant->room = room;
	ant->room->has_ant = 1;
	printf("L%d-%s ", ant->id, ant->room->name);
}

int		game_over(t_ant *ants, int antnum)
{
	int		i;

	if (!ants)
		return (1);
	i = 0;
	while (i < antnum)
	{
		if (ants[i].room->flag != ENDROOM)
			return (0);
		i++;
	}
	return (1);
}

void	game_loop(t_ant *ants, int antnum, t_list *rooms, t_list *paths)
{
	int		turn_ended;
	int		i;

	while (!game_over(ants, antnum))
	{
		turn_ended = 0;
		reset_ants(ants, antnum);
		while (!turn_ended && !game_over(ants, antnum))
		{
			turn_ended = 1;
			i = 0;
			while (i < antnum)
			{
				if (can_move(ants + i))
				{
					play(ants + i);
					turn_ended = 0;
				}
				i++;
			}
			write(1, "\n", 1);
		}
	}
	lemin_end(rooms, paths);
}
