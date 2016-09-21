/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:49:34 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/12/15 15:51:08 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count_int(int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		i++;
		return (i);
	}
	while (nbr > 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static char		*ft_n_is_neg(char *str, int n, int len)
{
	n = -n;
	str[0] = '-';
	len--;
	while (len > 0)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

static char		*ft_n_is_pos(char *str, int n, int len)
{
	len--;
	while (len >= 0)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_count_int(n);
	str = (char *)malloc((len + 1) * (sizeof(char)));
	if (str == 0)
		return (NULL);
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n < 0)
		str = ft_n_is_neg(str, n, len);
	if (n >= 0)
		str = ft_n_is_pos(str, n, len);
	str[len] = '\0';
	return (str);
}
