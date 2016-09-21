/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 20:42:44 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 20:51:25 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new_lst)
{
	t_list	*tmp_lst;

	if (alst == NULL)
		return ;
	tmp_lst = *alst;
	if (*alst == NULL)
		*alst = new_lst;
	else
	{
		while (tmp_lst->next != NULL)
			tmp_lst = tmp_lst->next;
		tmp_lst->next = new_lst;
	}
	new_lst->next = NULL;
}
