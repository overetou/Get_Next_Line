/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:19:50 by overetou          #+#    #+#             */
/*   Updated: 2017/11/13 13:19:52 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s2[j = 0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < len && s2[j])
	{
		j = 0;
		while (s1[i] != s2[j] && s1[i] && i < len)
			i++;
		if (s1[i] == s2[j] && s1[i] && i < len)
		{
			while (s1[i] == s2[j] && s1[i] && s2[j] && i < len)
			{
				i++;
				j++;
			}
			if (s2[j] != '\0')
				i = i - j + 1;
		}
	}
	return ((s2[j]) ? NULL : (char *)s1 + (i - j));
}
