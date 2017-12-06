/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:29:48 by overetou          #+#    #+#             */
/*   Updated: 2017/11/14 15:29:59 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void *p;

	if ((p = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
