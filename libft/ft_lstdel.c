/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:33:04 by overetou          #+#    #+#             */
/*   Updated: 2017/11/23 14:33:06 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *buff;

	if (alst)
	{
		next = *alst;
		while (next)
		{
			buff = next;
			next = buff->next;
			ft_lstdelone(&buff, del);
		}
		*alst = NULL;
	}
}
