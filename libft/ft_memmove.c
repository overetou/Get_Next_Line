/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:47:08 by overetou          #+#    #+#             */
/*   Updated: 2017/11/10 17:47:10 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dst2;
	char			*src2;
	unsigned int	x;

	dst2 = (char *)dst;
	src2 = (char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (dst < src)
	{
		x = 0;
		while (len > 0)
		{
			dst2[x] = src2[x];
			x++;
			len--;
		}
	}
	else
	{
		while (len-- > 0)
			dst2[len] = src2[len];
	}
	return (dst);
}
