/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:03:03 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/23 17:11:56 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void			to_forest(t_trueway *tmp, int n)
{
	while ((n > 0) || ((n >= 0) && g_lemin.ants == 1))
	{
		tmp = g_trueway;
		while (tmp->next != NULL)
		{
			if (tmp->next->busy != 0)
			{
				tmp->number = tmp->ants - tmp->a + 1;
				tmp->a--;
				ft_printf("L%d-%s ", tmp->number, tmp->name);
			}
			else
				tmp->busy = 0;
			tmp = tmp->next;
		}
		(n - g_lemin.ants >= 0) ? ft_printf("\n") : 0;
		n--;
	}
}

int				to_run(t_trueway *tmp, int n, int i, int f)
{
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
				ft_printf("L%d-%s ", tmp->number, tmp->name);
			}
			tmp = tmp->next;
		}
		((g_lemin.ants == 1 && f == 2) ||
				(n == g_lemin.ants && f == 2)) ? 0 : ft_printf("\n");
		i++;
		tmp = g_trueway;
	}
	return (n);
}

void			run_forest(void)
{
	int			i;
	t_trueway	*tmp;
	int			n;
	int			f;

	f = 0;
	i = 0;
	n = 0;
	tmp = g_trueway;
	while (tmp)
	{
		tmp = tmp->next;
		f++;
	}
	tmp = g_trueway;
	n = to_run(tmp, n, i, f);
	tmp = g_trueway;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->busy = 0;
	if (g_lemin.ants != 1 && f != 2)
		to_forest(tmp, n);
	tmp = g_trueway;
	if (g_lemin.ants == 1 && f != 2)
		ft_printf("L%d-%s ", 1, tmp->name);
}

t_trueway		*add_trueway(char *str)
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

void			add_trueway_add(char *str)
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
