/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:18:40 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/25 12:18:44 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_d
{
	int				diese;
	int				sign;
	int				type;
	int				side;
	int				zero;
	int				space;
	int				dot;
	int				width;
	int				tmp_width;
	int				preci;
	int				pourcent;
}					t_d;

int					g_count;

int					ft_printf(char *str, ...);
int					ft_atoi(const char *str);
int					ft_o_count(unsigned int wc);
int					ft_nbr_octet(wchar_t wc);
void				ft_o_count_bis(wchar_t *str, t_d *d);
void				char_e(char *str, char c, t_d *d);
void				intmax(int64_t nbr, char c, t_d *d);
void				u_intmax(uint64_t nbr, char c, t_d *d);
void				print_s_low(char *str, t_d *d);
void				print_c_low(unsigned char c, t_d *d);
void				print_c_upp(wchar_t c, t_d *d);
void				print_d_intmax(int64_t nbr, t_d *d);
void				print_u_uintmax(uint64_t nbr, t_d *d);
void				print_x_uintmax(uint64_t nbr, char c, t_d *d);
void				print_o_uintmax(uint64_t nbr, t_d *d);
void				print_pourcent(t_d *d);
void				non_valid_conv(char c, t_d *d);
void				check_type_int(int nbr, char c, t_d *d);
void				check_convert(char *str, t_d *d, va_list ap);
char				*check_flags(char *str, t_d *d);
char				*ft_strrev(char *str);
void				ft_putcharf(unsigned char c);
void				ft_putwchar(unsigned int wc);
void				ft_putwstr(wchar_t *str, t_d *d);
void				ft_putstrf(const char *str);

#endif
