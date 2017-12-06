/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:24:19 by overetou          #+#    #+#             */
/*   Updated: 2017/11/14 17:24:21 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_climb(const char *s)
{
	unsigned int	x;

	x = 0;
	while (s[x] == ' ' || s[x] == '\t' || s[x] == '\n')
		x++;
	return (x);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	l;
	char			*nstr;

	if (!s)
		return (NULL);
	x = ft_climb(s);
	y = x;
	y = ft_strlen(s);
	l = 0;
	if ((y != x && y != 0))
	{
		y--;
		while (s[y] == ' ' || s[y] == '\t' || s[y] == '\n')
			y--;
		l = ++y - x;
	}
	if ((nstr = (char *)ft_memalloc(l + 1)) == NULL)
		return (NULL);
	while (x < y)
		*nstr++ = s[x++];
	*nstr = '\0';
	nstr -= l;
	return (nstr);
}
