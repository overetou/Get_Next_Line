/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:15:04 by overetou          #+#    #+#             */
/*   Updated: 2017/11/10 12:15:07 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (j < n && s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
