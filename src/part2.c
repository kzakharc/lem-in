/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:03:03 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/21 13:03:05 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		run_forest(void)
{
	int 		i;
	t_trueway	*tmp;
	int			n;

	i = 0;
	n = 0;
	tmp = g_trueway;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->busy = 1;
	tmp = g_trueway;
	while (i < g_lemin.ants)
	{
		while (tmp->next != NULL)
		{
			if (tmp->next->busy != 0)
			{
				tmp->number = tmp->ants - tmp->a + 1;
				n = tmp->number;
				tmp->busy = 1;
				tmp->a--;
				ft_printf(MAG "L%d" RESET "-" YEL "%s " RESET,
						  tmp->number, tmp->name);
				tmp = tmp->next;
			}
			else
				tmp = tmp->next;
		}
		ft_printf("\n");
		i++;
		tmp = g_trueway;
	}
	tmp = g_trueway;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->busy = 0;
	while (n > 0)
	{
		tmp = g_trueway;
		while (tmp->next != NULL)
		{
			if (tmp->next->busy != 0)
			{
				tmp->number = tmp->ants - tmp->a + 1;
				tmp->a--;
				ft_printf(MAG "L%d" RESET "-" YEL "%s " RESET,
						  tmp->number, tmp->name);
				tmp = tmp->next;
			}
			else
			{
				tmp->busy = 0;
				tmp = tmp->next;
			}
		}
		ft_printf("\n");
		n--;
	}

}

t_trueway	*add_trueway(char *str)
{
	t_trueway	*tmp;

	tmp = malloc(sizeof(t_trueway));
	if (tmp)
	{
		tmp->name = str;
		tmp->busy = 0;
		tmp->number = 0;
		tmp->ants = g_lemin.ants;
		tmp->a = g_lemin.ants;
		tmp->next = g_trueway;
	}
	return (tmp);
}

void		add_trueway_add(char *str)
{
	t_trueway	*tmp;

	tmp = g_trueway;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_trueway *)malloc(sizeof(t_trueway));
	tmp->next->name = str;
	tmp->next->busy = 0;
	tmp->next->number = 0;
	tmp->next->ants = g_lemin.ants;
	tmp->next->a = g_lemin.ants;
	tmp->next->next = NULL;
}