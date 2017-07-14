/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:23:01 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/13 17:23:02 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		validation_links(void)  // TODO fix it
{
	int i;
	t_room *tmp;

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

int		validation_coor(char *str, int first)
{
	int i;
	int error;

	i = 0;
	error = 0;
	while (str[i])
	{
		if ((str[i] != ' ') && !(ft_isdigit(str[i])) && (str[i] != '-'))
			error++;
		else if ((str[i] == '-') && ft_isdigit(str[i - 1]))
			error++;
		i++;
	}
	error += count_digit(str);
	if (error == 0)
	{
		g_lemin.x_room = ft_atoi(str);
		if (ft_isspace(*str))
			str++;
		while (!(ft_isspace(*str)))
			str++;
		g_lemin.y_room = ft_atoi(str);
		if (repitCoor(first))
			return (1);
	}
	return (0);
}

int 	repitCoor(int first)
{
	t_room *tmp;

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

