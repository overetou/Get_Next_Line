/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:17:01 by overetou          #+#    #+#             */
/*   Updated: 2017/11/14 17:17:03 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*pstr;
	unsigned int	x;

	if (s1 && s2)
	{
		x = ft_strlen(s1) + ft_strlen(s2);
		if ((pstr = ft_strnew(x)) == NULL)
			return (NULL);
		ft_strcpy(pstr, s1);
		ft_strcat(pstr, s2);
		return (pstr);
	}
	return (NULL);
}
