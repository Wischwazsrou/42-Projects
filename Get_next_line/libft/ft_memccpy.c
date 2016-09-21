/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:30:50 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 22:52:49 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *v_dest, const void *v_src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned int	i;

	i = 0;
	dest = (unsigned char *)v_dest;
	src = (unsigned char *)v_src;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
			return (&v_dest[i + 1]);
		i++;
	}
	return (NULL);
}
