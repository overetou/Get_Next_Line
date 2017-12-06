/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:11:08 by overetou          #+#    #+#             */
/*   Updated: 2017/11/24 20:11:11 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tests(char *s1, char *s2, char *titl)
{
	ft_putstr(titl);
	if (ft_strcmp(s1, s2) == 0)
		ft_putstr(": ok\n");
	else
		ft_putstr(": ko\n");
}
