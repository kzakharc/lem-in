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
typedef struct 	s_trueway t_trueway;

struct			s_trueway
{
	char 		*name;
	int			busy;
	int 		number;
	int 		ants;
	int 		a;
	t_trueway	*next;
};

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
	int         q;
	int 		visit;
	int 		number;
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
	int 		n;
	char		*name_start;
	char		*name_end;
}				t_lemin;

t_room			*g_room;
t_data			*g_data;
t_link			*g_link;
t_lemin			g_lemin;
t_trueway		*g_trueway;

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
t_trueway		*add_trueway(char *str);
void			add_trueway_add(char *str);
void			add_data(char *str);
int				validation_coor(char *str, int first);
int				validation_room(int first);
int				validation_links(void);
int 			validation_true_link(char *str);
int 			repitCoor(int first);
void			print_data(void);
int				write_true_link(void);
void            write_start_end(void);
int				shortest_distance(int count, int i);
int 			write_distance(t_truelink *tmp, int *mass, int count, int d);
int				write_shortest_distance(void);
void			run_forest(void);

#endif
