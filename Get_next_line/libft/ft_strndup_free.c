/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:28:14 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/12/17 14:21:17 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strndup_free(const char *str, size_t size)
{
	char			*cpy_str;
	unsigned int	i;

	i = 0;
	cpy_str = (char*)malloc((size + 1) * sizeof(str));
	if (cpy_str == 0)
		return (NULL);
	while (i < size)
	{
		cpy_str[i] = str[i];
		i++;
	}
	cpy_str[i] = '\0';
	free((void *)str);
	return (cpy_str);
}
