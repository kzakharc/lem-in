/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:38:24 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/13 17:38:25 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int 	count_digit(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && ft_isspace(str[i - 1]))
			c++;
		i++;
	}
	if (c == 2)
		return (0);
	else
		return (1);
}

int 	count_space(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	return (i);
}

void	clean_before_start(void)
{
	g_room = NULL;
	g_data = NULL;
	g_link = NULL;
	g_lemin.n = 0;
	g_lemin.ants = 0;
	g_lemin.x_room = 0;
	g_lemin.y_room = 0;
	g_lemin.fl_ants = 0;
	g_lemin.fl_rooms = 0;
	g_lemin.fl_links = 0;
	g_lemin.fl_end = 0;
	g_lemin.fl_start = 0;
	g_lemin.error = 0;
}