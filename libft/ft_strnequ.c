/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:53:17 by overetou          #+#    #+#             */
/*   Updated: 2017/11/14 16:53:19 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int x;

	if (s1 && s2)
	{
		x = 0;
		if (n == 0)
			return (1);
		n--;
		while (s1[x] == s2[x] && s1[x] && s2[x] && x < n)
			x++;
		return ((s1[x] - s2[x] != 0) ? 0 : 1);
	}
	return (0);
}
