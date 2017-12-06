/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:09:39 by overetou          #+#    #+#             */
/*   Updated: 2017/11/12 14:09:41 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	x;
	unsigned char	*ps1;
	unsigned char	*ps2;

	x = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (x < n && ps1[x] == ps2[x])
		x++;
	if (x == n)
		return (0);
	return (ps1[x] - ps2[x]);
}
