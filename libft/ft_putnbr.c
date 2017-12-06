/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:01:56 by overetou          #+#    #+#             */
/*   Updated: 2017/11/15 19:01:58 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putnbr(int n)
{
	int				mem;
	unsigned int	div;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	div = 1;
	while (n / div >= 10)
		div = div * 10;
	while (div >= 1)
	{
		mem = (n / div);
		ft_putchar(mem + '0');
		n = n - (mem * div);
		div = div / 10;
	}
}
