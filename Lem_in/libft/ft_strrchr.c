/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:15:31 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/29 22:16:35 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*dest;
	unsigned int	i;
	int				j;

	i = 0;
	j = -1;
	dest = (char *)str;
	while (i <= (ft_strlen(str)))
	{
		if (dest[i] == (char)c)
			j = i;
		i++;
	}
	if (j >= 0)
		return (&dest[j]);
	return (0);
}
