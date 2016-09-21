/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:19:17 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 22:51:57 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *v_dest, const void *v_src, size_t n)
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
		i++;
	}
	return (v_dest);
}
