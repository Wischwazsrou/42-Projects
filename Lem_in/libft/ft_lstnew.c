/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 20:51:44 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 14:19:49 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (list)
	{
		list->content = malloc(content_size);
		if (list->content == NULL)
			return (NULL);
		if (content != NULL)
		{
			list->content = ft_memmove(list->content, content, content_size);
			list->next = NULL;
		}
		else
		{
			list->content = NULL;
			content_size = 0;
		}
	}
	return (list);
}
