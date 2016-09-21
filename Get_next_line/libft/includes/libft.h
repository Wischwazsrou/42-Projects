/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:04:35 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/04 00:26:53 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putendl(const char *str);
void				ft_putstr(const char *str);
void				ft_putchar(char c);
char				*ft_itoa(int n);
char				**ft_strsplit(const char *str, char c);
char				*ft_strtrim(const char *str);
char				*ft_strjoin(const char *str1, const char *str2);
char				*ft_strjoin_free(const char *str1, const char *str2);
char				*ft_strsub(const char *str, unsigned int start, size_t len);
int					ft_strnequ(const char *str1, const char *str2, size_t n);
int					ft_strequ(const char *str1, const char *str2);
char				*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char				*ft_strmap(const char *str, char (*f)(char));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
void				ft_striter(char *str, void (*f)(char *));
void				ft_strclr(char *str);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strrchr(const char *str, int c);
char				*ft_strchr(const char *str, int c);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strncat(char *str1, const char *str2, size_t n);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *str);
char				*ft_strdup_free(const char *str);
char				*ft_strndup(const char *str, size_t size);
char				*ft_strndup_free(const char *str, size_t size);
size_t				ft_strlen(const char *str);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memchr(const void *str1, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_bzero(void *str, size_t n);
void				*ft_memset(void *str, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd_back(t_list **alst, t_list *new_list);

#endif
