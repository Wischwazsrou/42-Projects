/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:38:21 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/29 14:31:40 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	unsigned int	i;
	unsigned int	len;
	int				result;
	char			*dest;

	i = 0;
	dest = (char *)str;
	len = ft_strlen(to_find);
	if (to_find[i] == '\0')
		return (dest);
	while (str[i] != '\0' && ((i + len) <= n))
	{
		if (str[i] == to_find[0])
		{
			result = ft_strncmp(&str[i], to_find, len);
			if (result == 0)
				return (&dest[i]);
		}
		i++;
	}
	return (NULL);
}
