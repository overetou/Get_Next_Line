/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:55:52 by overetou          #+#    #+#             */
/*   Updated: 2017/08/19 13:11:25 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && needle[j])
	{
		j = 0;
		while (haystack[i] != needle[j] && haystack[i])
			i++;
		if (haystack[i] == needle[j] && haystack[i] && needle[j])
		{
			while (haystack[i] == needle[j] && haystack[i] && needle[j])
			{
				i++;
				j++;
			}
			if (needle[j] != '\0')
				i = i - j + 1;
		}
	}
	return ((needle[j]) ? NULL : (char *)haystack + (i - j));
}
