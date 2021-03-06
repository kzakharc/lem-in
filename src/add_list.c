/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:29:06 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/23 18:38:37 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_truelink	*add_true_link(t_room *replica, char *str)
{
	t_truelink *tmp;

	tmp = malloc(sizeof(t_truelink));
	while (ft_strcmp(replica->n_room, str))
		replica = replica->next;
	if (tmp && !ft_strcmp(replica->n_room, str))
	{
		tmp->nbr = replica;
		tmp->next = g_room->link;
	}
	return (tmp);
}

t_link		*add_link(void)
{
	t_link *tmp;

	tmp = malloc(sizeof(t_link));
	if (tmp)
	{
		tmp->f_room = g_lemin.first_rm;
		tmp->s_room = g_lemin.second_rm;
		tmp->next = g_link;
	}
	return (tmp);
}

void		print_data(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while (tmp != NULL)
	{
		ft_printf("%s\n", tmp->str);
		ft_strdel(&tmp->str);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void		add_data(char *str, t_data *data)
{
	t_data *tmp;

	tmp = data;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_data *)malloc(sizeof(t_data));
	tmp->next->str = ft_strdup(str);
	tmp->next->next = NULL;
}

t_room		*add_room(void)
{
	t_room		*tmp;
	static int	i;

	i++;
	tmp = malloc(sizeof(t_room));
	if (tmp)
	{
		tmp->n_room = g_lemin.str_rm;
		tmp->x = g_lemin.x_room;
		tmp->y = g_lemin.y_room;
		tmp->q = 0;
		tmp->visit = 0;
		tmp->number = i;
		tmp->link = NULL;
		tmp->next = g_room;
	}
	return (tmp);
}
