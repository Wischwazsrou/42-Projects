/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:11:13 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 20:50:50 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_lst;
	t_list	*lst2;
	t_list	*new_lst;

	begin_lst = NULL;
	lst2 = lst;
	while (lst2 != NULL)
	{
		new_lst = ft_lstnew(NULL, 0);
		if (new_lst == NULL)
			return (NULL);
		new_lst = f(lst2);
		ft_lstadd_back(&begin_lst, new_lst);
		lst2 = lst2->next;
	}
	return (begin_lst);
}
