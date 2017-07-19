/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:57:15 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/19 15:57:17 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void    write_true_link(void)
{
    t_link *tmp;
    t_room *copy;
    t_room *replica;

    copy = g_room;
    replica = g_room;
    while (g_room != NULL)
    {
        tmp = g_link;
        while (tmp != NULL)
        {
            if (!ft_strcmp(g_room->n_room, tmp->f_room))
                g_room->link = add_true_link(replica, tmp->s_room);
            if (!ft_strcmp(g_room->n_room, tmp->s_room))
                g_room->link = add_true_link(replica, tmp->f_room);
            tmp = tmp->next;
        }
        g_room = g_room->next;
    }
    g_room = copy;
}
