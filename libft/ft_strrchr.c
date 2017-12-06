/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:20:20 by overetou          #+#    #+#             */
/*   Updated: 2017/11/12 16:20:22 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int x;

	x = 0;
	while (s[x])
		x++;
	if (c == '\0')
		return ((char *)s + x);
	while (--x >= 0)
	{
		if (s[x] == c)
			return ((char *)s + x);
	}
	return (0);
}
