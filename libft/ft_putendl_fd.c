/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:17:06 by overetou          #+#    #+#             */
/*   Updated: 2017/11/15 19:17:10 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putendl_fd(char const *s, int fd)
{
	int x;

	x = 0;
	while (s[x])
		ft_putchar_fd(s[x++], fd);
	ft_putchar_fd('\n', fd);
}
