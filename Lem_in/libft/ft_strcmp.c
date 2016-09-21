/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:01:54 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 14:20:11 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str, const char *str2)
{
	int i;

	i = 0;
	while ((unsigned char)str[i] == (unsigned char)str2[i])
	{
		if ((unsigned char)str[i] == '\0' && (unsigned char)str2[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)str[i] - (unsigned char)str2[i]);
}
