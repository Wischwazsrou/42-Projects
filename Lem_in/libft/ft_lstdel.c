/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:09:23 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 14:18:43 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst1;
	t_list	*lst2;

	lst1 = *alst;
	while (lst1 != NULL)
	{
		lst2 = lst1->next;
		ft_lstdelone(&lst1, (*del));
		lst1 = lst2;
	}
	*alst = NULL;
}
