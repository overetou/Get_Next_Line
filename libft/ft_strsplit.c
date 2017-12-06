/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:16:02 by overetou          #+#    #+#             */
/*   Updated: 2017/11/15 16:16:51 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**ft_filler(char **tab, char const *s, char c, size_t n)
{
	unsigned int x;
	unsigned int i;
	unsigned int j;
	unsigned int y;

	i = 0;
	x = 0;
	while (x < n)
	{
		y = 0;
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if ((tab[x] = (char *)ft_memalloc(j - i + 1)) == NULL)
			return (NULL);
		while (i < j)
			tab[x][y++] = s[i++];
		tab[x++][y] = '\0';
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	n;
	char			**tab;

	if (!s || !c)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	if ((tab = (char **)malloc(sizeof(char *) * (n + 1))) == NULL)
		return (NULL);
	tab[n] = 0;
	return (ft_filler(tab, s, c, n));
}
