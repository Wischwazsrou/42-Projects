/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:23:16 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/06/17 21:33:16 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libftprintf/includes/ft_printf.h"

typedef struct		s_room
{
	char			*name;
	char			**connections;
	char			*type;
	char			**map;
}					t_room;

typedef struct		s_data
{
	int				move;
	int				solution;
	int				current_solution;
	int				max_sol;
	int				start;
	int				end;
	int				n_rooms;
	int				ants;
	int				count;
	int				c;
	int				max_move;
	int				min_move;
	int				diff;
	int				coups;
	int				*moves;
	int				color;
	int				flag;
	int				show_moves;
	int				show_coups;
	int				show_path;
	char			*connection;
	char			**shit;
}					t_data;

typedef struct		s_path
{
	char			*room;
	struct s_path	*next;
	struct s_path	*previous;
	int				ant;
}					t_path;

typedef struct		s_c_file
{
	char			*line;
	char			**tab_line;
	int				start_count;
	int				end_count;
}					t_c_file;

t_room				*make_map(t_data *data, t_room *room);
int					count_rooms(char **tab_rooms, t_data *data);
int					solve(t_room *room, t_data *data, int i, t_path *path);
int					check_connection(t_room *room, char *connection);
int					check_room(char *room, t_data *data, t_path *path);
int					lst_check(char *room, t_path **solution);
int					controller(t_data *data);
int					count_move(t_path *path);
int					set_room(char **list_room, t_room *room, int i, char *line);
int					find_solution(t_room *room, t_data *data, t_path *path);
void				check_bonus(int ac, char **av, t_data *data);
void				print_bonus(t_path **solution, t_data *data);
void				print_options();
void				count_solutions(t_room *room, t_data *data);
t_path				**algo(t_room *room, t_data *data, t_path **solution);
void				init_data(t_data *data);
void				parse(t_data *data, t_room *room, char **tab_rooms);
void				ft_error(int i);
void				lst_init(t_path *path, t_room *room, t_data *data);
void				lst_delone(t_path *path);
t_path				**print(t_path **solution, t_data *data, t_room *room);
void				put_in_lst(t_room *room, t_data *data, t_path *path, int i);
t_path				**print_bis(t_path **solution, t_data *data, int n_sol,
						t_path **begin);
void				print_ter(t_path **solution, t_data *data, int n, int i);
t_path				*lst_add(t_path *path, char *room);
t_path				*lst_new(char *room, t_path *path);
char				**check_tab_room(char **tab_room);
int					ft_tab_len_max(char **tab_line, int length_max);
int					ft_isroom(char **tab_line);
int					check_cmd1(t_c_file *c_file, char **tab_room, int i);
int					check_cmd2(t_c_file *c_file, char **tab_room, int i);
char				**check_cmd3(t_c_file *c_file, char **tab_room, int i);
int					ft_pass_comment(char **tab_room, int i);

#endif
