/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 17:35:42 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/11 17:35:43 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"
#include <stdio.h>

t_data	*for_help(char *line, t_data *data)
{
	int flag;

	flag = 0;
	if ((count_space(line) == 0) && (line[0] != '#'))
		record_link_ant(line);
	else if ((count_space(line) == 2) && (line[0] != '#'))
		record_room(line);
	else if (line[0] == '#')
		flag = comment(line, 0, data);
	else
		g_lemin.error++;;
	if (flag == 0)
		data = record_data(line, data);
	return (data);
}

int 	main(void)
{
	char	*line;
	t_data	*data;

	data = NULL;
	clean_before_start();
	line = NULL;
	while (get_next_line(0, &line) > 0)
		data = for_help(line, data);
	if (!g_lemin.fl_ants || !g_lemin.fl_rooms || !g_lemin.fl_links ||
			!g_lemin.fl_start || !g_lemin.fl_end || g_lemin.error > 0)
	{
		ft_printf(RED "ERROR\n" RESET);
		return (0);
	}
    write_true_link() ? 0 : g_lemin.error++;
	write_shortest_distance() == -1 ? 0 : g_lemin.error++;
	if (g_lemin.error == 0)
		print_data(data);
	else
	{
		ft_printf(RED "ERROR\n" RESET);
		return (0);
	}
	run_forest();
	return (0);
}
