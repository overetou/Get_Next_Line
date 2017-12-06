/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:59:49 by overetou          #+#    #+#             */
/*   Updated: 2017/11/26 14:59:50 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstaddlink(t_list *lst, char *content, size_t content_size)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		if ((tmp = (t_list *)malloc(sizeof(*tmp))) == NULL)
			return (NULL);
		if (content == NULL)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			if ((tmp->content = ft_memalloc(content_size)) == NULL)
				return (NULL);
			ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
			tmp->next = lst;
		}
	}
	return (tmp);
}
