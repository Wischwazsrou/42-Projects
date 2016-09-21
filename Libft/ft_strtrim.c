/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:54:26 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 23:00:42 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_custom_cpy(char const *s, char *str, int l, int i)
{
	int j;

	j = 0;
	while (j < l - i + 1)
	{
		str[j] = s[j + i];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	len = (int)ft_strlen(s) - 1;
	if (len + 1 == i)
	{
		str = (char*)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (len > 0 && ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n')))
		len--;
	str = (char*)malloc(sizeof(char) * (len - i + 1));
	if (str == NULL)
		return (NULL);
	str = ft_custom_cpy(s, str, len, i);
	return (str);
}
