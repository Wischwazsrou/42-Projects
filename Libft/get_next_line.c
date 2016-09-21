/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:42:16 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/10 12:53:56 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_right_size(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char		*ft_get_position(char **line, char *str)
{
	int i;

	i = ft_get_right_size(str);
	if (str[i] == '\0')
	{
		*line = ft_strdup(str);
		return (NULL);
	}
	if (str[i] == '\n')
	{
		*line = ft_strndup(str, i);
		str = ft_strchr(str, '\n');
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str;
	char		buffer[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strnew(1);
	if (str != NULL)
		str = ft_get_position(line, str + 1);
	if (str == NULL)
	{
		while ((!(str = ft_strchr(*line, '\n'))) &&
				(ret = read(fd, buffer, BUFF_SIZE)))
		{
			if (ret < 0)
				return (-1);
			buffer[ret] = '\0';
			*line = ft_strjoin(*line, buffer);
		}
		if (ret == 0 && *line[0] == '\0')
			return (0);
		*line = ft_strndup(*line, ft_get_right_size(*line));
	}
	return (1);
}
