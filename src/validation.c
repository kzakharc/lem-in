/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:23:01 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/23 18:39:47 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		validation_true_link(char *str)
{
	t_truelink	*tmp;

	tmp = g_room->link;
	while (tmp != NULL)
	{
		if (!ft_strcmp(str, tmp->nbr->n_room))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		validation_links(void)
{
	int		i;
	t_room	*tmp;

	i = 0;
	tmp = g_room;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->n_room, g_lemin.first_rm) ||
				!ft_strcmp(tmp->n_room, g_lemin.second_rm))
			i++;
		tmp = tmp->next;
	}
	if (i == 2)
		return (1);
	else
		return (0);
}

int		validation_room(int first)
{
	t_room *tmp;

	tmp = g_room;
	if (first == 1)
		return (1);
	else
	{
		while (tmp != NULL)
		{
			if (!(ft_strcmp(tmp->n_room, g_lemin.str_rm)))
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int		validation_coor(char *str, int first, int i)
{
	int error;

	error = 0;
	while (str[++i])
	{
		if ((str[i] != ' ') && !(ft_isdigit(str[i])) && (str[i] != '-'))
			error++;
		else if ((str[i] == '-') && ft_isdigit(str[i - 1]))
			error++;
	}
	error += count_digit(str);
	if (error == 0)
	{
		g_lemin.f = ft_atoi(str);
		(g_lemin.f > 2147483647) ? error1() : (g_lemin.x_room = (int)g_lemin.f);
		if (ft_isspace(*str))
			str++;
		while (!(ft_isspace(*str)))
			str++;
		g_lemin.f = ft_atoi(str);
		(g_lemin.f > 2147483647) ? error1() : (g_lemin.y_room = (int)g_lemin.f);
		return (repitcoor(first));
	}
	return (0);
}

int		repitcoor(int first)
{
	t_room	*tmp;

	tmp = g_room;
	if (first == 1)
		return (1);
	else
	{
		while (tmp != NULL)
		{
			if ((g_lemin.x_room == tmp->x) &&
					(g_lemin.y_room == tmp->y))
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}
