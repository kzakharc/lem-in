/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:14:03 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/12 17:14:04 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_data	*record_data(char *line, t_data *data)
{
	static int	c;
	t_data		*tmp;

	c++;
	tmp = data;
	if (c == 1)
	{
		tmp = (t_data *)malloc(sizeof(t_data));
		tmp->str = ft_strdup(line);
		tmp->next = NULL;
	}
	if (c != 1)
		add_data(line, tmp);
	ft_strdel(&line);
	return (tmp);
}

void	record_room(char *line)
{
	int 		count;
	static int	first;

	count = 0;
	first++;
	g_lemin.fl_rooms = 1;
	(g_lemin.fl_links == 1 || g_lemin.fl_ants == 0) ? g_lemin.error++ : 0;
	while (*line != ' ')
	{
		*line == '-' ? g_lemin.error++ : 0;
		count++;
		line++;
	}
	g_lemin.str_rm = ft_strnew((size_t)count);
	g_lemin.str_rm = ft_strncpy(g_lemin.str_rm, line - count, (size_t)count);
	if (validation_coor(line, first) && !(ft_strchr(g_lemin.str_rm, '-')) &&
			(g_lemin.str_rm[0] != 'L') && validation_room(first))
	{
		g_room = add_room();
		g_lemin.n++;
	}
	else
		g_lemin.error++;
}

void	record_link_ant(char *line)
{
	int i;

	i = 0;
	if (!(ft_strchr(line, '-')))
	{
		while (line[i])
		{
			if (!(ft_isdigit(line[i])))
				g_lemin.error++;
			i++;
		}
		(g_lemin.fl_ants == 1) ? (g_lemin.error++) : (g_lemin.fl_ants = 1);
		(g_lemin.fl_rooms == 1 || g_lemin.fl_links == 1) ? g_lemin.error++ : 0;
		g_lemin.error == 0 ? g_lemin.ants = ft_atoi(line) : 0;
	}
	if (ft_strchr(line, '-'))
		re_link(line, i);
}

int     comment(char *line, int flag, t_data *data)
{
	(!ft_strcmp(line, "##start")) ? g_lemin.fl_start++ : 0;
	(!ft_strcmp(line, "##start") &&
			(g_lemin.fl_ants == 0)) ? g_lemin.error++ : 0;
    (!ft_strcmp(line, "##start")) ? flag++ : 0;
	(!ft_strcmp(line, "##end")) ? g_lemin.fl_end++ : 0;
	(!ft_strcmp(line, "##end") && (g_lemin.fl_ants == 0)) ? g_lemin.error++ : 0;
    (!ft_strcmp(line, "##end")) ? flag += 2 : 0;
	((g_lemin.fl_start > 1) || (g_lemin.fl_end > 1)) ? g_lemin.error++ : 0;
	if (g_lemin.error > 0)
		return (-1);
    if (flag > 0)
		flag = comm(line, flag, data);
    return (flag);
}

void	re_link(char *line, int i)
{
	(g_lemin.fl_rooms == 0 || g_lemin.fl_ants == 0) ? g_lemin.error++ : 0;
	g_lemin.fl_links = 1;
	while (*line != '-') {
		i++;
		line++;
	}
	g_lemin.first_rm = ft_strnew((size_t) i);
	g_lemin.first_rm = ft_strncpy(g_lemin.first_rm, line - i, (size_t) i);
	line++;
	g_lemin.second_rm = ft_strnew(ft_strlen(line));
	g_lemin.second_rm = ft_strcpy(g_lemin.second_rm, line);
	if (validation_links())
		g_link = add_link();
	else
		g_lemin.error++;
}

