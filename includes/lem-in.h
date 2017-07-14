/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 17:35:58 by kzakharc          #+#    #+#             */
/*   Updated: 2017/07/11 17:36:00 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# include "../Lib/src/libft/libft.h"
# include "../Lib/src/ft_printf/ft_printf.h"
# include "../Lib/src/get_next_line/get_next_line.h"

typedef struct	s_room t_room;

struct			s_room
{
	char 		*n_room;
	int 		x;
	int 		y;
	t_room		*next;
};

typedef struct 	s_data t_data;

struct 			s_data
{
	char 		*str;
	t_data		*next;
};

typedef struct	s_link t_link;

struct			s_link
{
	char 		*f_room;
	char 		*s_room;
	t_link		*next;
};

typedef struct 	s_lemin
{
	int 		ants;
	char 		*str_rm;
	int 		x_room;
	int			y_room;
	int 		fl_ants;
	int 		fl_rooms;
	int 		fl_links;
	int 		fl_start;
	int 		fl_end;
	int 		error;
	t_room		*start;
	t_room		*end;
}				t_lemin;

t_room			*g_room;
t_data			*g_data;
t_link			*g_link;
t_lemin			g_lemin;

int 			count_space(char *str);
void			record_room(char *line);
void			record_link_ant(char *line);
void			comment(char *line);
void			record_data(char *line);
t_room			*add_room(void);
void			add_data(char *str);
int				validation_coor(char *str, int first);
int				validation_room(int first);
int 			repitCoor(int first);
void			print_data(void);
void			clean_before_start(void);

#endif
