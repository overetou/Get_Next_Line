/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:05:58 by overetou          #+#    #+#             */
/*   Updated: 2017/11/12 16:06:01 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	unsigned int x;

	x = 0;
	while (s[x])
		x++;
	if (c == '\0')
		return ((char *)s + x);
	return (ft_memchr(s, c, x));
}
