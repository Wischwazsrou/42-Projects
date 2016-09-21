/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 00:07:40 by vklepper          #+#    #+#             */
/*   Updated: 2015/12/07 00:07:56 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define BUF_SIZE 21

int		check_d(char *tetri);
int		check_line(char *tetri);
int		check_placement(char *tetri);
int		to_put_answer_in_your_face(char **grid);
int		you_shall_not_pass(char **tetra_box, size_t n_tetra);
int		to_check_if_possible(char **grid, int x, int y, char *tetri);
int		one_ring(char **tetra_box, char **grid, size_t current, size_t n_tetra);
char	*copy_motherfucker(char *tetriminos, char *tetra_box);
char	**give_me_tetra(char *av, char **tetra_box);
char	**alloc_me_pliizzz(size_t size);
char	**to_never_forget(char **grid, int current);
char	**ok_forget_it(char **grid, int current);
char	**to_put_some_d(char **grid, int x, int y, char *tetri);
char	**feed_me_pliizzz(char **nogozone, size_t size, size_t x, size_t y);
size_t	palantir(char *av);
size_t	opti_size_box(size_t nbr_tetr);
void	i_am_your_master(char **tetra_box, size_t n_tetra);

#endif
