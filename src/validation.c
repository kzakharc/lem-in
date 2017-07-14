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

int		validation_room(int first)
{
	if (first == 1)
		return (1);
	else
	{
		while (g_room != NULL)
		{
			if (!(ft_strcmp(g_room->n_room, g_lemin.str_rm)))
				return (0);
			g_room = g_room->next;
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
	if (first == 1)
		return (1);
	else
	{
		while (g_room != NULL)
		{
			if ((g_lemin.x_room == g_room->x) &&
					(g_lemin.y_room == g_room->y))
				return (0);
			g_room = g_room->next;
		}
	}
	return (1);
}

