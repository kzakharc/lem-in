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

int 	main(void)
{
	char	*line;
	int 	fd;
    int     flag;

    flag = 0;
	fd = open("test", O_RDONLY);
	fd < 0 ? perror("fd error") : 0; // TODO delete before finish the project
	clean_before_start();
	while (get_next_line(fd, &line) > 0)
	{
		if ((count_space(line) == 0) && (line[0] != '#'))
			record_link_ant(line);
		else if ((count_space(line) == 2) && (line[0] != '#'))
			record_room(line);
		else if (line[0] == '#')
			flag = comment(line, fd, 0);  // TODO delete fd
		else
			g_lemin.error++;;
		if (flag == 0)
            record_data(line);
        else
            flag = 0;
		if (g_lemin.error > 0)
		{
			ft_printf(RED "ERROR\n" RESET);
			return (0);
		}
	}
	if (!g_lemin.fl_ants || !g_lemin.fl_rooms || !g_lemin.fl_links ||
			!g_lemin.fl_start || !g_lemin.fl_end)
	{
		ft_printf(RED "ERROR\n" RESET);
		return (0);
	}
    write_true_link() ? 0 : g_lemin.error++;
	write_shortest_distance() ? 0 : g_lemin.error++;
	if (g_lemin.error == 0)
	{
		print_data();
		ft_printf("\n");
	}
	else
	{
		ft_printf(RED "ERROR\n" RESET);
		return (0);
	}
	run_forest();
	while (1);
	return (0);
}
