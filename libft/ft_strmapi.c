/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:35:25 by overetou          #+#    #+#             */
/*   Updated: 2017/11/14 16:35:28 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
	x = 0;
	while (s[x])
	{
		ps[x] = f(x, s[x]);
		x++;
	}
	ps[x] = '\0';
	return (ps);
}
