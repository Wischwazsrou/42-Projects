/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:01:41 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 22:53:23 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *v_dest, const void *v_src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)v_dest;
	src = (unsigned char *)v_src;
	dest = dest + n;
	src = src + n;
	if (dest <= src)
		return (ft_memcpy(v_dest, v_src, n));
	while (n != 0)
	{
		*--dest = *--src;
		n--;
	}
	return (v_dest);
}
