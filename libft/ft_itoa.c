/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:04:10 by overetou          #+#    #+#             */
/*   Updated: 2017/11/15 17:04:11 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_put(int n, unsigned int div, char *str, char s)
{
	unsigned int x;

	x = 0;
	if (s == 1)
		str[x++] = '-';
	while (div != 0)
	{
		str[x++] = n / div + '0';
		n = n - ((n / div) * div);
		div = div / 10;
	}
	str[x] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	div;
	unsigned int	x;
	short			s;

	div = 1;
	x = 0;
	s = 0;
	if (n < 0)
	{
		s = 1;
		n = -n;
	}
	while (n / div >= 10)
	{
		div = div * 10;
		x++;
	}
	if ((str = (char *)ft_memalloc(x + 1 + s)) == NULL)
		return (NULL);
	return (ft_put(n, div, str, s));
}
