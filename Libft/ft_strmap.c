/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:37:55 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/28 21:43:34 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *str, char (*f)(char))
{
	char			*new_str;
	int				i;

	i = 0;
	new_str = (char *)malloc((ft_strlen(str) + 1) * (sizeof(char)));
	if (new_str == 0)
		return (NULL);
	while (str[i] != 0)
	{
		new_str[i] = f(str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
