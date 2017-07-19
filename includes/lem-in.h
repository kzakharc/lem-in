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
typedef struct	s_truelink t_truelink;
typedef struct 	s_data t_data;
typedef struct	s_link t_link;

struct			s_truelink
{
	t_room 		*nextdoor;
	t_truelink	*next;
};

struct			s_room
{
	char 		*n_room;
	int 		x;
	int 		y;
	t_truelink	*link;
	t_room		*next;
};

struct 			s_data
{
	char 		*str;
	t_data		*next;
};

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
	char 		*first_rm;
	char		*second_rm;
	int 		x_room;
	int			y_room;
	int 		fl_ants;
	int 		fl_rooms;
	int 		fl_links;
	int 		fl_start;
	int 		fl_end;
	int 		error;
	char		*name_start;
	char		*name_end;
}				t_lemin;

t_room			*g_room;
t_data			*g_data;
t_link			*g_link;
t_lemin			g_lemin;

int 			count_space(char *str);
int 			count_digit(char *str);
void			clean_before_start(void);
void			record_room(char *line);
void			record_link_ant(char *line);
int			    comment(char *line, int fd, int flag);  // TODO delete fd
void			record_data(char *line);
t_room			*add_room(void);
t_truelink		*add_true_link(t_room *replica, char *str);
t_link			*add_link(void);
void			add_data(char *str);
int				validation_coor(char *str, int first);
int				validation_room(int first);
int				validation_links(void);
int 			repitCoor(int first);
void			print_data(void);
void            write_true_link(void);
void			print_fucking_neiblabla(void);

#endif
