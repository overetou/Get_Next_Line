/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:45:05 by overetou          #+#    #+#             */
/*   Updated: 2017/11/10 19:45:06 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	x;
	unsigned char	*s2;
	unsigned char	c2;

	x = 0;
	c2 = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (x < n)
	{
		if (s2[x] == c2)
			return ((void *)s + x);
		x++;
	}
	return (NULL);
}
