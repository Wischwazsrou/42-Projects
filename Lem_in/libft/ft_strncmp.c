/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:13:59 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/05/20 18:11:24 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str, const char *str2, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)str[i] == '\0' && (unsigned char)str2[i] == '\0')
			return (0);
		if ((unsigned char)str[i] != (unsigned char)str2[i])
			return ((unsigned char)str[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
