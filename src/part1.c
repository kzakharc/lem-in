/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:57:15 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/23 18:39:15 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		write_shortest_distance(void)
{
	t_room		*tmp;
	t_room		*room;
	t_truelink	*l;

	tmp = g_room;
	while (tmp->visit != 2)
		tmp = tmp->next;
	g_trueway = add_trueway(tmp->n_room);
	l = tmp->link;
	while ((tmp->q != -1) && (l != NULL))
	{
		if ((l->nbr->q == tmp->q - 1 && l->nbr->visit == 1) || l->nbr->q == -1)
		{
			add_trueway_add(l->nbr->n_room);
			l->nbr->visit = 3;
			room = g_room;
			while (ft_strcmp(l->nbr->n_room, room->n_room))
				room = room->next;
			tmp = room;
			l = tmp->link;
		}
		else
			l = l->next;
	}
	return (tmp->q);
}

int		write_true_link(void)
{
	t_link *tmp;
	t_room *copy;
	t_room *replica;

	copy = g_room;
	replica = g_room;
	while (g_room != NULL)
	{
		tmp = g_link;
		while (tmp != NULL)
		{
			if (!ft_strcmp(g_room->n_room, tmp->f_room))
				if (validation_true_link(tmp->s_room))
					g_room->link = add_true_link(replica, tmp->s_room);
			if (!ft_strcmp(g_room->n_room, tmp->s_room))
				if (validation_true_link(tmp->s_room))
					g_room->link = add_true_link(replica, tmp->f_room);
			tmp = tmp->next;
		}
		g_room = g_room->next;
	}
	g_room = copy;
	write_start_end();
	return (shortest_distance(0, 0));
}

void	write_start_end(void)
{
	t_room	*tmp;

	tmp = g_room;
	while (tmp != NULL)
	{
		if (!ft_strcmp(g_lemin.name_start, tmp->n_room))
		{
			tmp->q = -1;
			tmp->visit = 1;
		}
		if (!ft_strcmp(g_lemin.name_end, tmp->n_room))
			tmp->visit = 2;
		tmp = tmp->next;
	}
}

int		shortest_distance(int count, int i)
{
	t_room	*tmp_room;
	t_room	*tmp;
	int		mass[g_lemin.n];

	tmp_room = g_room;
	while (tmp_room->q != -1)
		tmp_room = tmp_room->next;
	if (tmp_room->q == -1)
	{
		mass[count++] = tmp_room->number;
		i = write_distance(tmp_room->link, mass, count, 0);
	}
	tmp_room = g_room;
	while (tmp_room->visit != 2)
		tmp_room = tmp_room->next;
	while ((tmp_room->q == 0) && (count < g_lemin.n))
	{
		tmp = g_room;
		while ((tmp->number != mass[count]) && (tmp->next != NULL))
			tmp = tmp->next;
		i = write_distance(tmp->link, mass, i, tmp->q);
		count++;
	}
	return (tmp_room->q);
}

int		write_distance(t_truelink *tmp, int *mass, int count, int d)
{
	while (tmp != NULL)
	{
		if ((tmp->nbr->visit != 1))
		{
			mass[count] = tmp->nbr->number;
			tmp->nbr->q = d + 1;
			if (tmp->nbr->visit != 2)
				tmp->nbr->visit = 1;
			count++;
		}
		tmp = tmp->next;
	}
	return (count);
}
