/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:00:08 by overetou          #+#    #+#             */
/*   Updated: 2017/11/14 17:00:10 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*pstr;
	unsigned int	x;

	if (!s)
		return (NULL);
	x = 0;
	if ((pstr = ft_strnew(len)) == NULL)
		return (NULL);
	while (len-- > 0)
		pstr[x++] = s[start++];
	return (pstr);
}
