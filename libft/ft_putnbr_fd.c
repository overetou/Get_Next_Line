/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:19:40 by overetou          #+#    #+#             */
/*   Updated: 2017/11/15 19:19:42 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int				mem;
	unsigned int	div;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	div = 1;
	while (n / div >= 10)
		div = div * 10;
	while (div >= 1)
	{
		mem = (n / div);
		ft_putchar_fd(mem + '0', fd);
		n = n - (mem * div);
		div = div / 10;
	}
}
