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

void	record_data(char *line)
{
	static int	c;

	c++;
	if (c == 1)
	{
		g_data = (t_data *)malloc(sizeof(t_data));
		g_data->str = line;
		g_data->next = NULL;
	}
	if (c != 1)
		add_data(line);
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
		g_room = add_room();
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
		g_lemin.fl_ants = 1;
		(g_lemin.fl_rooms == 1 || g_lemin.fl_links == 1) ? g_lemin.error++ : 0;
		g_lemin.error == 0 ? g_lemin.ants = ft_atoi(line) : 0;
	}
	if (ft_strchr(line, '-'))
	{
		(g_lemin.fl_rooms == 0 || g_lemin.fl_ants == 0) ? g_lemin.error++ : 0;
		g_lemin.fl_links = 1;
		while (*line != '-')
		{
			i++;
			line++;
		}
		g_lemin.first_rm = ft_strnew((size_t)i);
		g_lemin.first_rm = ft_strncpy(g_lemin.first_rm, line - i, (size_t)i);
		line++;
		g_lemin.second_rm = ft_strnew(ft_strlen(line));
		g_lemin.second_rm = ft_strcpy(g_lemin.second_rm, line);
		if (validation_links())
			g_link = add_link();
		else
			g_lemin.error++;
	}
}

int     comment(char *line, int fd, int flag) // TODO delete fd
{
	(!ft_strcmp(line, "##start")) ? g_lemin.fl_start++ : 0;
    (!ft_strcmp(line, "##start")) ? flag++ : 0;
	(!ft_strcmp(line, "##end")) ? g_lemin.fl_end++ : 0;
    (!ft_strcmp(line, "##end")) ? flag += 2 : 0;
	((g_lemin.fl_start > 1) || (g_lemin.fl_end > 1)) ? g_lemin.error++ : 0;
    if (flag > 0)
    {
        record_data(line);
        while ((get_next_line(fd, &line) > 0) && g_lemin.error == 0) {
            ((!ft_strcmp(line, "##start")) ||
             (!ft_strcmp(line, "##end"))) ? g_lemin.error++ : 0;
            if ((count_space(line) == 2) && (line[0] != '#')) {
                record_room(line);
                if (g_lemin.error == 0) {
                    flag == 1 ? g_lemin.name_start = g_lemin.str_rm : 0;
                    flag == 2 ? g_lemin.name_end = g_lemin.str_rm : 0;
                    record_data(line);
                    return (flag);
                }
            } else if (line[0] == '#')
                record_data(line);
            else
                g_lemin.error++;
        }
    }
    return (flag);
}

