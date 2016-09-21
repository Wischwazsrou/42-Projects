/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 22:38:48 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/26 21:02:21 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *str1, char const *str2)
{
	int i;

	i = ft_strcmp(str1, str2);
	if (i == 0)
		return (1);
	else
		return (0);
}
