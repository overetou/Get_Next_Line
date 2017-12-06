/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:12:20 by overetou          #+#    #+#             */
/*   Updated: 2017/11/10 15:12:22 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	x;
	char			*src2;
	char			*dst2;

	x = 0;
	src2 = (char *)src;
	dst2 = (char *)dst;
	while (x < n)
	{
		dst2[x] = src2[x];
		x++;
	}
	return (dst);
}
