/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:43:40 by overetou          #+#    #+#             */
/*   Updated: 2017/11/10 16:43:45 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	x;
	unsigned char	*src2;
	unsigned char	*dst2;
	unsigned char	c2;

	x = 0;
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	c2 = (unsigned char)c;
	while (x < n)
	{
		dst2[x] = src2[x];
		if (src2[x] == c2)
			return (dst + x + 1);
		x++;
	}
	return (NULL);
}
