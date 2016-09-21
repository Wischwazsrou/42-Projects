/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:27:16 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/29 14:31:03 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*dest;
	int		result;
	int		i;

	i = 0;
	dest = (char *)str;
	if (to_find[i] == '\0')
		return (dest);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			result = ft_strncmp(&str[i], to_find, ft_strlen(to_find));
			if (result == 0)
				return (&dest[i]);
		}
		i++;
	}
	return (NULL);
}
