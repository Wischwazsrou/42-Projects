/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:07:32 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 21:45:27 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == '\0')
		return (NULL);
	while (i < len)
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
