/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:13:26 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/10 12:15:45 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**ft_strsplit_alloc1(char **split, char const *s, char c, int l)
{
	int		i;
	int		n;
	int		j;

	i = 0;
	n = 0;
	j = 0;
	while (i <= l)
	{
		if (s[i] == c && j > 0)
		{
			n++;
			j = 0;
		}
		else
			j++;
		i++;
	}
	split = (char**)malloc(sizeof(char*) * (n + 2));
	if (split == NULL)
		return (NULL);
	return (split);
}

static char		**ft_strsplit_alloc2(char **split, char const *s, char c, int l)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	j = 0;
	while (i <= l)
	{
		if (s[i] == c && j > 0)
		{
			split[n] = (char*)malloc(sizeof(char) * (j + 1));
			if (split[n] == NULL)
				return (NULL);
			n++;
			j = 0;
		}
		else
			j++;
		i++;
	}
	split[n] = (char*)malloc(sizeof(char) * (j + 1));
	if (split[n] == NULL)
		return (NULL);
	return (split);
}

static char		**ft_strsplit_cpy(char **split, char const *s, char c, int l)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	j = 0;
	while (i <= l)
	{
		if (s[i] != c)
		{
			split[n][j] = s[i];
			j++;
		}
		if (s[i] == c && j > 0)
		{
			split[n][j] = '\0';
			n++;
			j = 0;
		}
		i++;
	}
	split[n][j] = '\0';
	split[n + 1] = NULL;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		l;

	if (s == NULL)
		return (NULL);
	if (c == '\0')
		return (NULL);
	l = ft_strlen(s) - 1;
	while (l >= 0 && s[l] == c)
		l--;
	split = NULL;
	split = ft_strsplit_alloc1(split, s, c, l);
	if (split == NULL)
		return (NULL);
	split = ft_strsplit_alloc2(split, s, c, l);
	if (split == NULL)
		return (NULL);
	split = ft_strsplit_cpy(split, s, c, l);
	if (split[0][0] == '\0')
		split[0] = NULL;
	return (split);
}
