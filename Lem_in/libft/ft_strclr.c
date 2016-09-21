/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:57:24 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/27 14:03:42 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *str)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		str[i] = '\0';
		i++;
	}
}
