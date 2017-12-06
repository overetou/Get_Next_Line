/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:21:59 by overetou          #+#    #+#             */
/*   Updated: 2017/11/14 16:22:01 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	x;
	char			*ps;

	if (!s || !f)
		return (NULL);
	x = 0;
	while (s[x])
		x++;
	if ((ps = ft_strnew(x)) == NULL)
		return (NULL);
	ps[x] = '\0';
	while (--x != 0)
	{
		ps[x] = f(s[x]);
	}
	ps[x] = f(s[x]);
	return (ps);
}
