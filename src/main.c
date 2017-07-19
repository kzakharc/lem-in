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
			write(1, "ERROR\n", 6);
			return (0);
		}
	}
	if (!g_lemin.fl_ants || !g_lemin.fl_rooms || !g_lemin.fl_links ||
			!g_lemin.fl_start || !g_lemin.fl_end)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
    write_true_link();
	if (g_lemin.error == 0)
		print_data();
    print_fucking_neiblabla();
	return (0);
}
