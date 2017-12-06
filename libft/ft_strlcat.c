/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:36:37 by overetou          #+#    #+#             */
/*   Updated: 2017/11/12 14:36:39 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int x;
	unsigned int y;
	unsigned int len;

	x = 0;
	y = 0;
	while (dst[x] && x < size)
		x++;
	if (size <= x)
		return (x + ft_strlen(src));
	len = x;
	size--;
	while (src[y])
	{
		if (x < size)
			dst[x++] = src[y];
		y++;
	}
	dst[x] = '\0';
	return (len + y);
}
